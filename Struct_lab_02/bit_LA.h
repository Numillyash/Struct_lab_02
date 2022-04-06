#ifndef BIT_LA_H
#define BIT_LA_H

#include "config.h"

#define NUMBER_ARR_SIZE 256
#define NUMBER_SYSTEM_BASE 2
#define MILLERS_METHOD_ITERATIONS_NUMBER 20

/// <summary>
/// ���������, ����������� ������������� ��� � ���������� �������� ������
/// </summary>
typedef struct
{
    int current_count; // ������� ���������� ���������
    int size; // �������� ������ �������
    uint8_t mas[256]; // ������ ������
}number;

/// <summary>
/// ��������� ����������� ���
/// </summary>
/// <param name="a">������ ���</param>
/// <param name="b">������ ���</param>
/// <returns>��������� ��������</returns>
inline uint8_t XOR(uint8_t a, uint8_t b);

/// <summary>
/// ��������� ��
/// </summary>
/// <param name="a">��� �����</param>
/// <returns>��������� ��������</returns>
inline uint8_t NOT(uint8_t a);

/// <summary>
/// ��������� �
/// </summary>
/// <param name="a">������ ���</param>
/// <param name="b">������ ���</param>
/// <returns>��������� ��������</returns>
inline uint8_t AND(uint8_t a, uint8_t b);

/// <summary>
/// ������� ����� � �������������� ���
/// </summary>
/// <param name="value"></param>
void additional_code(number* value);

/// <summary>
/// ������� ����� �� ��������������� � ������ ���
/// </summary>
/// <param name="value"></param>
void nonadditional_code(number* value);

/// <summary>
/// �������������� ������ ��������� � ������ �������� � ������������� negative
/// </summary>
/// <returns>������ ���������</returns>
number init();

/// <summary>
/// ���������� ��������� ���������� ������
/// </summary>
/// <param name="value">������ �� ���������</param>
/// <returns>������ ���������, ���������� �������</returns>
number copy(number* value);

/// <summary>
/// ���������� ���������, � ������� �������� ������ ����� � ��������� int
/// </summary>
/// <param name="value">����� �����</param>
/// <returns>������ ���������, ���������� ������ �����</returns>
number int_to_number(int value);

/// <summary>
/// ���������� int, � ������� �������� ������ �����
/// </summary>
/// <param name="value">Number �����</param>
/// <returns>����� �����</returns>
int number_to_int(number* value);

/// <summary>
/// ���������� ���������, � ������� �������� ������ ����� � ��������� ull
/// </summary>
/// <param name="value">����� �����</param>
/// <returns>������ ���������, ���������� ������ �����</returns>
number ull_to_number(ull value);

/// <summary>
/// ���������� ull, � ������� �������� ������ �����
/// </summary>
/// <param name="value">Number �����</param>
/// <returns>����� �����</returns>
ull number_to_ull(number* value);

/// <summary>
/// ���������� number-������ ��� ���������� �����
/// </summary>
/// <param name="value">������ �� ������</param>
void normalize(number* value);

/// <summary>
/// ��������� char-������� � ����� ������� ��������� (����� ������ �����)
/// </summary>
/// <param name="object">������ �� ���������</param>
/// <param name="value">��������</param>
void add_digit(number* object, uint8_t value);

/// <summary>
/// �������� ��������� ����� (�������� �� ���� ������ ������)
/// </summary>
void offset_right(number* object);

/// <summary>
/// ���������� ���� � ����� (�������� �� ���� ������ �����)
/// </summary>
void offset_left(number* object);

/// <summary>
/// ������������� ����� � ������ �������
/// </summary>
/// <param name="value">������ �� �����</param>
void reverse(number* value);

/// <summary>
/// �������� ������ � ������ ����� ���, ��� �� �������� � ������
/// </summary>
/// <param name="value">������ �� �����</param>
void print_number_as_is(number* value);

/// <summary>
/// �������� ������ � ������ ����� � ���������� ��
/// </summary>
/// <param name="value">������ �� �����</param>
void print_number_decimal(number* value);

/// <summary>
/// �������� ������ � ������ �����
/// </summary>
/// <param name="value">������ �� �����</param>
void print_number(number* value);

/// <summary>
/// ��������� ����� � 0 (����� ����/�� ����� ����)
/// </summary>
/// <param name="object">�����, ������� ���������� ���������</param>
/// <returns>��������� ���������</returns>
BOOL is_zero(number* object);

/// <summary>
/// ��������� ����� � ������ ����� (�����/�� �����)
/// </summary>
/// <param name="value1">������ �����, ������� ���������� ��������</param>
/// <param name="value2">������ �����, ������� ���������� ��������</param>
/// <returns>��������� ���������</returns>
BOOL is_equal(number* value1, number* value2);

/// <summary>
/// ���������� ���� ����� � �������, � ������ ����������� ����� ������ �� ���� �����, � ���������� ��������� ���� number
/// </summary>
/// <param name="value1">������ �����</param>
/// <param name="value2">������ �����</param>
/// <returns>��������� ��������</returns>
number addition(number* value1, number* value2);

/// <summary>
/// �������� ���� ����� �� �������, � ������ ����������� ����� ������ �� ���� �����, � ���������� ��������� ���� number
/// </summary>
/// <param name="value1">������ �����</param>
/// <param name="value2">������ �����</param>
/// <returns>��������� ���������</returns>
number difference(number* value1, number* value2);

/// <summary>
/// �������� ���� ����� �� ������ � ���������� ��������� ���� number
/// </summary>
/// <param name="value1">������ �����</param>
/// <param name="value2">������ �����</param>
/// <returns>��������� ���������</returns>
number multiplication(number* value1, number* value2);

/// <summary>
/// ������� � ��������
/// </summary>
/// <param name="value1">�������</param>
/// <param name="value2">��������</param>
/// <param name="ost">�������</param>
/// <returns>�������</returns>
number division_with_module(number* value1, number* value2, number* ost);

/// <summary>
/// ���������� ������ �� ������� ����� a � ������� t �� b
/// </summary>
/// <param name="a">�������</param>
/// <param name="t">�������</param>
/// <param name="b">��������</param>
/// <returns>�������</returns>
number module_pow(number* a, number* t, number* b);

/// <summary>
/// ���������� ��� ���� �����
/// </summary>
/// <param name="value1">������ �����</param>
/// <param name="value2">������ �����</param>
/// <returns>���</returns>
number euclide_algorithm(number* value1, number* value2);

/// <summary>
/// ���������� ��� ���� ����� � ������� ����������
/// </summary>
/// <param name="value1">������ �����</param>
/// <param name="value2">������ �����</param>
/// <param name="values">������ � ��������</param>
/// <returns>���</returns>
number euclide_algorithm_modifyed(number* value1, number* value2, number* values);

/// <summary>
/// ��������� ���������� ����� � �������� ����������� ���
/// </summary>
/// <param name="bit_count">���-�� ���</param>
/// <returns>��������������� �����</returns>
number generate_random(int bit_count);

/// <summary>
/// �������� ����� �� ��������
/// </summary>
/// <param name="value">�����</param>
/// <returns>1 - ���� �������, 0 - ���� ���������</returns>
BOOL Millers_method(number* value);

#endif // !BIT_LA_H