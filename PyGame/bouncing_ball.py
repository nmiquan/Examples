import pygame, sys
pygame.init()

size = width, height = 640, 480
speed = [1, 5]
black = 0, 0, 0

screen = pygame.display.set_mode(size)

ball = pygame.image.load("ball.bmp") # loading image
ballrect = ball.get_rect() # generate a Rect object

while 1:
    # check For exit
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()

    # insert code that use event to control game event

    # moving the ball 
    ballrect = ballrect.move(speed)
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]
        
    screen.fill(black) # erase screen
    screen.blit(ball, ballrect) # drawing of images
    pygame.display.flip() # make every thing drawn on the screen becomes visible
