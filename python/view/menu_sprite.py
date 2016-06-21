__author__ = 'Arin'
import pygame, os
class MenuSprite(pygame.sprite.Sprite):
    """Cursor class. A small border which highlights your selected tile"""
    def __init__(self, cursor, col, row):
        pygame.sprite.Sprite.__init__(self)
        self.image, self.rect = self.load_sprite(os.path.join("pixel_art","mainmenu.png"))
        self.cursor = cursor
        self.rect.topleft = self.cursor.x*60, self.cursor.y*60
        self.is_open = False
        self.col=col
        self.row=row
    def update(self):
        x = self.cursor.x
        y = self.cursor.y
        xp = x+1
        yp = y+1
        if x>self.col/2:
            xp=x-2
        if y>self.row/2:
            yp=y-2
        self.rect.topleft = xp*60, yp*60
    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert_alpha()
        return image, image.get_rect()
