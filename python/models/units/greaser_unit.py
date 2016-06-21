__author__ = 'Arin'
import random

from unit import Unit, m_dist
from constants import CONST


class GreaserUnit(Unit):
    key  = "Greaser"
    def __init__(self, x, y, map, team):
        max_hp = random.randint(CONST.greaser_min_hp,
                                CONST.greaser_max_hp)
        strength = random.randint(CONST.greaser_min_strength,
                                  CONST.greaser_max_strength)
        finesse = random.randint(CONST.greaser_min_finesse,
                                 CONST.greaser_max_finesse)
        wit = random.randint(CONST.greaser_min_wit,
                             CONST.greaser_max_wit)
        style = random.randint(CONST.greaser_min_style,
                               CONST.greaser_max_style)
        path = CONST.sh_gr_im_path if team == CONST.sharks \
            else CONST.jt_gr_im_path
        sfx = CONST.gr_at
        super(GreaserUnit, self).__init__(x, y, map, team, max_hp, strength,
                                          finesse, wit, style,
                                          CONST.greaser_movement, path,sfx)
        self.at_sfx.set_volume(2)
    def calculate_damage(self, unit):
        """Calculates damage for GreaserUnit"""
        base_dmg = self.finesse
        reduction = unit.finesse * .5 + unit.strength * .5
        return base_dmg - reduction

    def can_attack(self, attack_x, attack_y):
        """Direct attack"""
        s = super(GreaserUnit, self).can_attack(attack_x, attack_y)
        return m_dist(self.x, self.y, attack_x, attack_y) == 1 and s

    def special_attack(self, attack_x, attack_y):
        """Twirl. Damage all adjacent enemies."""
        r = self.attack(self.x + 1, self.y)
        l = self.attack(self.x - 1, self.y)
        u = self.attack(self.x, self.y + 1)
        d = self.attack(self.x, self.y - 1)
        return r or u or l or d
