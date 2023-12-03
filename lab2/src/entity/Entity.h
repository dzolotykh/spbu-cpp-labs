#ifndef LAB2_ENTITY_H
#define LAB2_ENTITY_H

class Entity {
 protected:
  int health{};
  int max_health{};
public:
    int get_max_health() const;

    int get_max_mana() const;

protected:
    int mana{};
  int max_mana{};

  int damage;

 public:
  Entity(int _max_health, int _max_mana, int _damage);
  Entity();

  void set_health(int _health);
  void set_mana(int _mana);
  void add_health(int _health);
  void add_mana(int _mana);
  bool is_alive() const;

  int get_health() const;

  int get_mana() const;

  int get_damage() const;
};

#endif // LAB2_ENTITY_H
