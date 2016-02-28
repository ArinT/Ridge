__author__ = 'Arin'
import pygame, os


class UnitSprite(pygame.sprite.Sprite):
    def __init__(self, unit):
        """Creates a sprite from a unit which can be manipulated by pygame"""
        pygame.sprite.Sprite.__init__(self)
        self.unit = unit
        self.image, self.rect = self.load_sprite(self.unit.image_path)
        self.rect.topleft = self.unit.x * 60, self.unit.y * 60
        self.original = self.image.copy()
        self.tired = self.image.copy()
        c = self.image.get_masks()
        self.tired_mask = ((c[0]/2,c[1]/2,c[2]/2,c[3]))
        self.tired.set_masks(self.tired_mask)
    def update(self, *args):

        if not self.unit.is_alive:
            self.remove()
            self.kill()
            return
        self.rect.topleft = self.unit.x * 60, self.unit.y * 60
        if not self.unit.is_ready():
            self.image = self.tired
        else:
            self.image = self.original

    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert_alpha()
        return image, image.get_rect()