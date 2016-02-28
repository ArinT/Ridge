__author__ = 'Arin'
import pygame, os

class CursorSprite(pygame.sprite.Sprite):
    """Cursor class. A small border which highlights your selected tile"""
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image, self.rect = self.load_sprite(os.path.join("PixelArt","Cursor.png"))
        self.x = 0
        self.y = 0
        self.rect.topleft = self.x*60, self.y*60
    def update(self, *args):
        self.rect.topleft = self.x*60, self.y*60
    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert_alpha()
        return image, image.get_rect()
