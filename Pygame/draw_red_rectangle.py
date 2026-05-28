import pygame
pygame.init()

#屏幕和时间初始化
screen = pygame.display.set_mode((400,200))
clock = pygame.time.Clock()
#定义方块
square_pos = pygame.Rect(295,192,5,5)
#定义球
circle_pos = pygame.Vector2(150,150)
circle_spd = pygame.Vector2()
circle_rad = 2
circle_acc = 0.01
circle_spd_mul = 0.99
bounce_str = 1.0#碰撞的弹性系数

while True:
    if pygame.event.get(pygame.QUIT):
        break
    #方块的运动控制
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        square_pos.y -= 10
    if keys[pygame.K_DOWN]:
        square_pos.y += 10
    if keys[pygame.K_LEFT]:
        square_pos.x -= 10
    if keys[pygame.K_RIGHT]:
        square_pos.x += 10
    #球的追杀逻辑
    circle_spd *= circle_spd_mul#阻尼，防止无限加速
    circle_spd += (pygame.Vector2(square_pos.center) - circle_pos)*circle_acc
    circle_pos += circle_spd
    #球的碰撞逻辑
    if circle_pos[0]<circle_rad:#如果球心到墙的距离小于半径
        circle_pos.update(circle_rad,circle_pos[1])#把球和墙相切
        circle_spd.update(-circle_spd[0]*bounce_str, circle_spd[1])#更新速度，法向反向切向不变
    elif circle_pos[0]>screen.get_width()-circle_rad:
        circle_pos.update(screen.get_width()-circle_rad,circle_pos[1])
        circle_spd.update(-circle_spd[0]*bounce_str,circle_spd[1])
    elif circle_pos[1]<circle_rad:
        circle_pos.update(circle_pos[0], circle_rad)
        circle_spd.update(circle_spd[0], -circle_spd[1]*bounce_str)
    elif circle_pos[1]>screen.get_height()-circle_rad:
        circle_pos.update(circle_pos[0], screen.get_height() - circle_rad)
        circle_spd.update(circle_spd[0], -circle_spd[1] * bounce_str)
    #屏幕刷新
    screen.fill("black")
    pygame.draw.rect(screen, "red", square_pos)
    pygame.draw.circle(screen,"yellow",circle_pos,circle_rad)
    pygame.display.flip()
    clock.tick(60)
pygame.quit()