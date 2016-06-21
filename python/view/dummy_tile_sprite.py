__author__ = 'Arin'
import pygame, os
class DummyTileSprite(pygame.sprite.Sprite):
    """Cursor class. A small border which highlights your selected tile"""
    def __init__(self,name,pane):
        pygame.sprite.Sprite.__init__(self)
        self.image, self.rect = self.load_sprite(name)
        self.pane = pane
        self.rect.topleft = self.pane.x*60+3, (self.pane.y+2)*60-3
    def update(self, *args):
        self.rect.topleft = self.pane.x*60+3, (self.pane.y+2)*60-3

    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert_alpha()
        return image, image.get_rect()