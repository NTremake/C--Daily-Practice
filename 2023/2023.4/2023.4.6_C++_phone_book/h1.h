#pragma once
#include <iostream>
using namespace std;

void addPerson(struct AddressBooks* abs);
void showPerson(struct AddressBooks* abs);
int isExist(AddressBooks* abs, string name);
void delPerson(AddressBooks* abs);
void findPerson(AddressBooks* abs);
void modifyPerson(AddressBooks* abs);
void cleanPerson(AddressBooks* abs);