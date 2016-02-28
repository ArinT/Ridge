__author__ = 'Arin'
import random

from Unit import Unit, m_dist
from Constants import CONST


class SquabblerUnit(Unit):
    key = "Squabbler"
    def __init__(self, x, y, map, team):
        max_hp = random.randint(CONST.squabbler_min_hp,
                                CONST.squabbler_max_hp)
        strength = random.randint(CONST.squabbler_min_strength,
                                  CONST.squabbler_max_strength)
        finesse = random.randint(CONST.squabbler_min_finesse,
                                 CONST.squabbler_max_finesse)
        wit = random.randint(CONST.squabbler_min_wit,
                             CONST.squabbler_max_wit)
        style = random.randint(CONST.squabbler_min_style,
                               CONST.squabbler_max_style)
        path = CONST.sh_sq_im_path if team == CONST.sharks \
            else CONST.jt_sq_im_path
        sfx = CONST.sq_at
        super(SquabblerUnit, self).__init__(x, y, map, team, max_hp, strength,
                                            finesse, wit, style,
                                            CONST.squabbler_movement, path,sfx)

    def calculate_damage(self, unit):
        """Calculates damage for SquabblerUnit"""
        base_dmg = self.wit
        reduction = unit.wit * .5 + unit.finesse * .5
        return base_dmg - reduction

    def can_attack(self, attack_x, attack_y):
        """Direct attack"""
        s = super(SquabblerUnit, self).can_attack(attack_x, attack_y)
        return m_dist(self.x, self.y, attack_x, attack_y) in (1, 2) and s

    def special_attack(self, attack_x, attack_y):
        """Quarrel. Disables enemy unit for one turn. Can't implement yet.
        Replacement. Belittle. Reduces enemy stats"""
        if self.can_attack(attack_x, attack_y):
            attackee = self.map.unit_at(attack_x, attack_y)
            attackee.demoralize = True
            return True
        return False