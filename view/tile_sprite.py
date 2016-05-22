__author__ = 'Arin'
import pygame, os


class TileSprite(pygame.sprite.Sprite):
    """Creates a sprite from a tile which can be manipulated by pygame"""
    def __init__(self, tile):
        pygame.sprite.Sprite.__init__(self)
        self.tile = tile
        self.image, self.rect = self.load_sprite(self.tile.image_path)
        self.rect.topleft = self.tile.x * 60, self.tile.y * 60
        self.blue_tint =  self.image.copy()
        self.red_tint = self.image.copy()
        self.original = self.image.copy()
        c = self.image.get_masks()
        self.blue_mask = ((0,0,c[2], c[3]))
        self.red_mask  = ((0,0,c[0],c[3]))
        self.blue_tint.set_masks(self.blue_mask)
        self.red_tint.set_masks(self.red_mask)

    def update(self, *args):
        if self.tile.marked:
            self.image = self.blue_tint
        elif self.tile.at_marked:
            self.image = self.red_tint
        else:
            self.image = self.original

    def load_sprite(self, name):
        fullname = os.path.join(os.path.abspath(os.path.curdir), name)
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image at:', name
            raise SystemExit, message
        image = image.convert()
        return image, image.get_rect()