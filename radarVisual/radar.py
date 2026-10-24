import pygame
import math
import serial
import time

# ---------- CONFIG ----------
COM_PORT = 'COM7'      # Arduino COM port
BAUD_RATE = 9600
WIDTH, HEIGHT = 800, 800
MAX_DISTANCE = 5       # adjust to your sensor's max cm
FADE_SPEED = 0.92       # fading trail (0.0 = instant fade, 1.0 = no fade)

# ---------- SETUP SERIAL ----------
try:
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # give Arduino time to reset
    print("connec")
except Exception as e:
    print("❌ Failed to open serial:", e)
    ser = None

# ---------- PYGAME SETUP ----------
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Ultrasonic Radar")
clock = pygame.time.Clock()

# Colors
GREEN = (0, 255, 0)
RED = (255, 0, 0)
BLACK = (0, 0, 0)
DARK_GREEN = (0, 50, 0)

CENTER = (WIDTH // 2, HEIGHT // 2)
SCALE = (WIDTH // 2) / MAX_DISTANCE

angle = 0
points = []

# Surface to store trails
trail_surface = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)

# ---------- RADAR BACKGROUND ----------
def draw_radar_bg():
    screen.fill(BLACK)
    for r in range(50, WIDTH // 2, 50):
        pygame.draw.circle(screen, DARK_GREEN, CENTER, r, 1)
    for a in range(0, 360, 30):
        rad = math.radians(a)
        x = CENTER[0] + math.cos(rad) * WIDTH // 2
        y = CENTER[1] - math.sin(rad) * HEIGHT // 2
        pygame.draw.line(screen, DARK_GREEN, CENTER, (x, y), 1)

# ---------- MAIN LOOP ----------
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    draw_radar_bg()

    # ---------- READ SERIAL ----------
    if ser and ser.in_waiting > 0:
        line = ser.readline().decode(errors='ignore').strip()
        if line:
            # print("Received:", line)  # Uncomment for debugging
            if ',' in line:
                try:
                    a, d = line.split(',')
                    angle = int(a)
                    distance = float(d)
                    if 0 < distance <= MAX_DISTANCE:
                        points.append((angle, distance, time.time()))
                except ValueError:
                    pass

    # ---------- DRAW RED BLIPS ----------
    new_points = []
    for a, d, t in points:
        if time.time() - t < 1.0:  # show for 1 second
            rad = math.radians(a)
            x = CENTER[0] + math.cos(rad) * d * SCALE
            y = CENTER[1] - math.sin(rad) * d * SCALE
            pygame.draw.circle(trail_surface, RED, (int(x), int(y)), 6)
            new_points.append((a, d, t))
    points = new_points

    # ---------- FADE TRAIL ----------
    fade = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    fade.fill((0, 0, 0, int((1 - FADE_SPEED) * 255)))
    trail_surface.blit(fade, (0, 0))

    screen.blit(trail_surface, (0, 0))

    # ---------- DRAW SWEEP LINE ----------
    sweep_rad = math.radians(angle)
    x = CENTER[0] + math.cos(sweep_rad) * WIDTH // 2
    y = CENTER[1] - math.sin(sweep_rad) * HEIGHT // 2
    pygame.draw.line(screen, GREEN, CENTER, (x, y), 3)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
if ser:
    ser.close()
