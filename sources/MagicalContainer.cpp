#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>
namespace ariel {

    bool MagicalContainer::is_prime(int num) {
        if(num <= 1) {
            return false;
        }
        for(int divider = 2; divider <= sqrt(num); divider++) {
            if(num % divider == 0) {
                return false;
            }
        }
        return true;
    }

    MagicalContainer::MagicalContainer() {}

    int MagicalContainer::size() {
        return this->elements.size();
    }
    bool comparePtrToInt(int* a, int* b) { return (*a < *b); }

    void MagicalContainer::addElement(int num) {
        this->elements.push_back(num);
        this->sorted_elements.insert(num);
        if (this->is_prime(num)) {
            this->prime_elements.push_back(num);
        }
    }

    void MagicalContainer::removeElement(int num) {
        this->elements.erase(remove(this->elements.begin(), this->elements.end(), num), this->elements.end());
        this->sorted_elements.erase(num);
        this->prime_elements.erase(remove(this->prime_elements.begin(), this->prime_elements.end(), num), this->prime_elements.end());
    }


    /* AscendingIterator */
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer magicalContainer) {
        this->mc = magicalContainer;
    }
    int MagicalContainer::AscendingIterator::operator*() const {
        return *(this->it);
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        this->it.operator++();
        this->location++;
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &it) const {
        return this->it == it.it;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &it) const {
        return !this->operator==(it);
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin() {
        this->it = this->mc.sorted_elements.begin();
        return *this;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        this->it = this->mc.sorted_elements.end();
        return *this;
    }

    /* SideCrossIterator */
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer magicalContainer) {
        this->mc = magicalContainer;
    }
    int MagicalContainer::SideCrossIterator::operator*() const {
        return 1;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        this->location++;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &it) const {
        return true;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &it) const {
        return !this->operator==(it);
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin() {
        return *this;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end() {
        return *this;
    }


    /* PrimeIterator */
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer magicalContainer) {
        this->mc = magicalContainer;
    }
    int MagicalContainer::PrimeIterator::operator*() const {
        return *(this->it);
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        this->it.operator++();
        this->location++;
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &it) const {
        return this->it == it.it;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &it) const {
        return !this->operator==(it);
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin() {
        this->it = this->mc.prime_elements.begin();
        return *this;
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end() {
        this->it = this->mc.prime_elements.end();
        return *this;
    }


}
