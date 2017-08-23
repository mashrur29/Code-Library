char charArray[] = {'A','Z', 'K', 'L' };

size_t arraySize = sizeof(charArray)/sizeof(*charArray);

std::sort(charArray, charArray+arraySize);