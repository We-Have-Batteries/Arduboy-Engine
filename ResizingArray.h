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
    // Setup::tinyfont.print("Current arr location: \n");
    // Setup::tinyfont.print(address);
    // Setup::tinyfont.print("\n");

    Setup::tinyfont.print("CurIndex minus size: ");
    Setup::tinyfont.print(((int)currentIndex - (int)size));
    Setup::tinyfont.print("\n");

    // if we hit the end of the array, make it larger
    if ((int)currentIndex - (int)size >= 0) {
      // Add spacing to the array
      T* newArr = new T[size + spacingAmount];
      // Should copy all elements from arr into newArr
      memcpy(newArr, arr, size * sizeof(T*));
      delete[] arr;
      arr = newArr;
      size += spacingAmount;

      // for (int i = 0; i < size; i++) {
      //   Setup::tinyfont.print("New Arr ");
      //   Setup::tinyfont.print(i);
      //   Setup::tinyfont.print(" value: ");
      //   Setup::tinyfont.print(arr[i]);
      //   Setup::tinyfont.print("\n");
      // }
    }


    Setup::tinyfont.print("Size: ");
    Setup::tinyfont.print(size);
    Setup::tinyfont.print("\n");
    Setup::tinyfont.print("Current index: ");
    Setup::tinyfont.print(currentIndex);
    Setup::tinyfont.print("\n");

    arr[currentIndex] = value;
    currentIndex++;
  }

  void Remove(T value, bool destructive = true){
    for (int i = 0; i < size; i++){
      // If we found the item
      if (arr[i] == value){
        // Clear the data here
        if (destructive)
          delete arr[i];
        // // Fill everything from above downwards
        // for (int j = i; j < size-1; j++){
        //   arr[j] = arr[j+1];
        // }
        // Copy the elements above this point down to this spot
        memcpy(arr+i, arr, (size-i) * sizeof(T));
        size--;
        currentIndex--;
        break;
      }
    }
    // If we've removed enough objects to be further than 2 spacings away
    if ((int)currentIndex - (int)size < spacingAmount*-2){
      T* newArr = new T[size - spacingAmount];
      // Should copy all elements from arr into newArr
      memcpy(newArr, arr, size * sizeof(T*));
      delete[] arr;
      arr = newArr;
      size -= spacingAmount;
    }
  }

  /// Returns how many objects are currently in the array
  int GetSize(){
    return currentIndex;
  }

  T GetValue(int index){
    if (index >= 0 && index < currentIndex) {
      return arr[index];
    }
    if (index > currentIndex && index < size) {
      return NULL;
    }
    return NULL;
  }

  T operator[](int index) {
    if (index >= 0 && index < currentIndex) {
      return arr[index];
    }
    if (index > currentIndex && index < size) {
      return NULL;
    }
    return NULL;
  }

  // thing here
private:
  T* arr;
  uint16_t currentIndex;
  uint16_t size;
};

#endif