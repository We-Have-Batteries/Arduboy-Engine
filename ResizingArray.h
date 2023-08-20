#ifndef RESIZINGARRAY_H
#define RESIZINGARRAY_H

#include "Setup.h"

template <typename T>
class ResizingArray{
public:
  uint8_t spacingAmount;

  ResizingArray(uint8_t spacingAmount){
    currentIndex = 0;
    size = spacingAmount;
    this->spacingAmount = spacingAmount;
    arr = new T[spacingAmount];
  }

  Push(T value){
    // Leaving this here for later because it's useful for comparing memory addresses!
    // Maybe make a static helper function somewhere as a tool!
    // uintptr_t address = reinterpret_cast<uintptr_t>(arr);
    // Setup::tinyfont.print(F("Current arr location: \n"));
    // Setup::tinyfont.print(address);
    // Setup::tinyfont.print(F("\n"));

    // Setup::tinyfont.print(F("CurIndex minus size: "));
    // Setup::tinyfont.print(((int)currentIndex - (int)size));
    // Setup::tinyfont.print(F("\n"));

    // if we hit the end of the array, make it larger
    if (size - currentIndex == 0) {
      // Add spacing to the array
      T* newArr = new T[size + spacingAmount];
      // Should copy all elements from arr into newArr
      memcpy(newArr, arr, currentIndex * sizeof(T));
      delete[] arr;
      arr = newArr;
      size += spacingAmount;

      // for (int i = 0; i < size; i++) {
      //   Setup::tinyfont.print(F("New Arr "));
      //   Setup::tinyfont.print(i);
      //   Setup::tinyfont.print(F(" value: "));
      //   Setup::tinyfont.print(arr[i]);
      //   Setup::tinyfont.print(F("\n"));
      // }
    }


    // Setup::tinyfont.print(F("Size: "));
    // Setup::tinyfont.print(size);
    // Setup::tinyfont.print(F("\n"));
    // Setup::tinyfont.print(F("Current index: "));
    // Setup::tinyfont.print(currentIndex);
    // Setup::tinyfont.print(F("\n"));

    arr[currentIndex] = value;
    currentIndex++;
  }

  void Remove(T value, bool destructive = true){
    for (int i = 0; i < size-1; i++){
      // If we found the item
      if (arr[i] == value){
        // Clear the data here
        if (destructive){
          // delete arr[i];
          free(arr[i]);
        }

        // Copy the elements above this point down to this spot
        memcpy(arr+i, arr+i+1, (size-i) * sizeof(T));
        currentIndex--;
        break;
      }
    }

    // If we've removed enough objects to be further than 2 spacings away
    if ((int)size - (int)currentIndex >= spacingAmount*2){
      // Setup::tinyfont.print(F("Current index < size - space*2\n"));
      // Remove spacing amount spots
      size -= spacingAmount;
      T* newArr = new T[size];
      // Copies all elements from arr into newArr
      memcpy(newArr, arr, currentIndex * sizeof(T));
      delete[] arr;
      arr = newArr;
    }
  }

  /// Returns how many objects are currently in the array
  int GetSize(){
    return size;
  }

  int GetCurIndex(){
    return currentIndex;
  }

  /*
  T GetValue(int index){
    if (index >= 0 && index < currentIndex) {
      return arr[index];
    }
    if (index > currentIndex && index < size) {
      return NULL;
    }
    return NULL;
  }
  */

  T& operator[](int index) {
    if (index >= 0 && index < currentIndex) {
      return arr[index];
    }

    // Exception handling disabled on embedded systems, so i'm just gonna crash!
    // throw OutOfBoundsException(index);
    // return arr[0];
    return arr[size+1];
  }

  /// Uses selection sort to put the objects in ascending order
  void AscentionSort(bool (*XLessThanY)(T, T)){
    for (int i = 0; i < currentIndex; i++){
      int smallestIndex = i;
      for (int j = i; j < currentIndex; j++){
        if (XLessThanY(arr[j], arr[smallestIndex])){
          smallestIndex = j;
        }
      }
      T oldThing = arr[i];
      arr[i] = arr[smallestIndex];
      arr[smallestIndex] = oldThing;
    }
  }

  void DescentionSort(bool (&XLessThanY)(T, T)){
    for (int i = 0; i < currentIndex; i++){
      int largestIndex = i;
      for (int j = i; j < currentIndex; j++){
        if (!XLessThanY(arr[j], arr[largestIndex])){
          largestIndex = j;
        }
      }
      T oldThing = arr[i];
      arr[i] = arr[largestIndex];
      arr[largestIndex] = oldThing;
    }
  }

  // thing here
private:
  T* arr;
  uint16_t currentIndex;
  uint16_t size;
};

#endif