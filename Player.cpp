#include "Player.h"
#include <iostream>

Player::Player() : MaxAttack(50), MinAttack(0), CurrentHealth(100), MaxHealth(100), Confidence(20), Combo(1) {}

Player::Player(string Name, string Class, int MaxAttack, int MinAttack, int CurrentHealth, int MaxHealth, int Confidence, int Combo) : 
Name(Name), Class(Class), MaxAttack(MaxAttack), MinAttack(MinAttack), CurrentHealth(CurrentHealth), MaxHealth(MaxHealth), Confidence(Confidence), Combo(Combo) {}

void Player::setStats(int A, int B, int C, int D, int E, int F) {
    MaxAttack = A; MinAttack = B;
    CurrentHealth = C; MaxHealth = D;
    Confidence = E; Combo = F;
}

void Player::takeBack(Player Attacker) {
    int Damage = Attacker.MaxAttack / 50; CurrentHealth -= Damage; cout << Name << " took " << Damage << " damage in return!" << endl << endl;
} 

void Player::takeDamage(Player Attacker) {
    int Damage = static_cast<int>(rand() % (Attacker.MaxAttack - Attacker.MinAttack)) + Attacker.MinAttack;
    CurrentHealth -= Damage;
    cout << Name << " took " << Damage << " damage!" << endl << endl;
}

void Player::takeConfidence(Player Attacker) {
    int Damage = static_cast<int>(Confidence * Combo);
    CurrentHealth -= Damage; Attacker.Combo = 1;
}

void Player::fullHeal() { CurrentHealth = MaxHealth; }

void Player::display() {
    cout << "Name: " << Name << " " << Class << endl
        << "Health: " << CurrentHealth << " / " << MaxHealth << endl
        << "Attack: " << MinAttack << " - " << MaxAttack << endl
        << "Confidence: " << Confidence * Combo << " (" << Confidence << " x " << Combo << ")";
        if (Combo >= 3) { cout << " <-- Nice! Your combo is more than two! You can type \"" << Combo * Confidence << "\" in battle to use your special attack!"; }
        cout << endl;
}