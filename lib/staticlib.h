#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

// ������� ������ �����
void clearInputBuffer();

// ���� ������������������ int
int inputIntArray(int *array, int size);

// ���� ������������������ double
int inputDoubleArray(double *array, int size);

// ����� int ������� � ���� ����������� ������������������
void printIntArray(int *array, int size);

// ����� int ������� � ���� �������
void printIntArrayTable(int *array, int size, int elementsPerRow);

// ����� double ������� � ���� ����������� ������������������
void printDoubleArray(double *array, int size);

// ����� double ������� � ���� �������
void printDoubleArrayTable(double *array, int size, int elementsPerRow);

#endif // HEAD_H_INCLUDED
