__author__ = 'Arin'


class Tile(object):
    """superclass for tile objects"""

    def __init__(self, def_val, path, is_accessible, x, y):
        """Superclass constructor which is called in every subclass"""
        self.defense_value = def_val
        self.image_path = path
        self.unit = None
        self.is_occupied = False
        self.is_accessible = is_accessible
        self.x = x
        self.y = y
        self.marked = False
        self.at_marked = False

    def remove_unit(self):
        self.is_occupied = False
        r = self.unit
        self.unit = None
        return r

    def add_unit(self, unit):
        self.is_occupied = True
        self.unit = unit

    def get_defense_value(self):
        return self.defense_value

    def get_image_path(self):
        return self.image_path
