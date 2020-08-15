#include <iostream>
#include <string>
using namespace std;

// 1-------------------------------------------------------------------------

int multiplyLoop(int base, int times)
{
    int res = 0;
    for (int i = 0; i < times; i++)
    {
        res += base;
    }
    return res;
}

int multiply(int base, int times = 1, int count = 0, int result = 0)
{
    // cout << count << " " << result << " " << base << " " << times << "\n";
    if (count == times)
        return result;
    // cout << result << "\n";
    return multiply(base, times, count += 1, result += base);
}

// 2-------------------------------------------------------------------------
//checar este código
int squareLoop(int base, int pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++)
    {
        cout << res << " " << base << "\n";
        res *= base;
    }
    return res;
}

int square(int base, int pow, int count = 0, int res = 0, int multcount = 0, int multres = 0)
{
    if (pow == count)
        return res;
    if (res == 0)
        res += multiply(base, base, multcount += 1, multres += base);
    res += multiply(res, base, multcount += 1, multres += base);
    cout << res << "\n";

    return square(base, pow, count += 1, res);
}
// Checar codigo de arriba (2)
// 3-------------------------------------------------------------------------

int maxNumLoop(int arr[], int arrSize)
{
    int max = INT8_MIN;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int maxNum(int arr[], int size, int pos = 0, int greatest = 0)
{
    if (pos == size)
        return greatest;
    if (arr[pos] > greatest)
        greatest = arr[pos];
    return maxNum(arr, size, pos += 1, greatest);
}

// 4-------------------------------------------------------------------------

int vocalsLoop(string frase)
{
    int count = 0;
    for (int i = 0; i < frase.length(); i++)
    {
        if (tolower(frase[i]) == 'a' || tolower(frase[i]) == 'e' || tolower(frase[i]) == 'i' || tolower(frase[i]) == 'o' || tolower(frase[i]) == 'u')
            count++;
    }
    return count;
}

int vocals(string frase, int count = 0, int i = 0)
{
    if (tolower(frase[i]) == 'a' || tolower(frase[i]) == 'e' || tolower(frase[i]) == 'i' || tolower(frase[i]) == 'o' || tolower(frase[i]) == 'u')
        count++;
    if (i == frase.length())
        return count;
    return vocals(frase, count, i += 1);
}

// 5-------------------------------------------------------------------------

// 6-------------------------------------------------------------------------

int digitosLoop(int numOriginal)
{
    string numberString = to_string(numOriginal);
    int sum = 0, current;
    for (int i = 0; i < numberString.length(); i++)
    {
        current = numberString[i] - '0';
        sum += current;
    }
    return sum;
}

int digitos(int original, int pos = 0, int res = 0)
{
    string numberString = to_string(original);
    int current = numberString[pos] - '0';
    if (pos == numberString.length())
        return res;
    return digitos(original, pos += 1, res += current);
}

// 7-------------------------------------------------------------------------

string reverseLoop(string original)
{
    string reversed = "";
    std::cout << "La palabra original es '" << original << "'" << std::endl;
    for (int i = original.length() - 1; i >= 0; i--)
    {
        reversed += original[i];
    }
    std::cout << "La palabra invertida es: ";
    return reversed;
}

string reverse(string original, string reversed = "")
{
    static int i = original.length() - 1;
    if (i == -1)
    {
        std::cout << "La palabra original es: " << original << std::endl;
        std::cout << "La palabra invertida es: ";
        return reversed;
    }
    reversed += original[i];
    i--;
    return reverse(original, reversed);
}

// 8-------------------------------------------------------------------------

string palindromoLoop(string palabra)
{
    int j = palabra.length() - 1;
    for (int i = 0; i < palabra.length(); i++)
    {
        // cout << palabra[i] << " " << palabra[j] << "\n";
        if (palabra[i] == palabra[j])
            j--;
        else
            return "no es palindromo";
    }
    return "si es palindromo";
}

string palindromo(string palabra, int j, int i = 0)
{
    // cout << palabra[i] << " " << palabra[j] << "\n";
    if (i == palabra.length())
        return "si es palindromo";
    if (palabra[i] == palabra[j])
        return palindromo(palabra, j -= 1, i += 1);
    return "no es palindromo";
}
// main----------------------------------------------------------------------

int main()
{
    // 1
    // cout << multiplyLoop(4, 5) << "\n";
    // cout << multiply(5, 5) << "\n";
    // 2
    // std::cout << squareLoop(5,2) << std::endl;
    // std::cout << square(5, 5) << std::endl;
    // 3
    // int arr[] = {35, 243, 24465, 767, 354, 4646, 3245, 4647, 976};
    // std::cout << maxNumLoop(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
    // std::cout << maxNum(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
    // 4
    // std::cout << vocalsLoop("Hola, me llamo sebastian") << std::endl;
    //std::cout << vocals("Hola, me llamo Sebastian") << std::endl;
    // 6
    // std::cout << digitosLoop(65) << std::endl;
    // std::cout << digitos(645) << std::endl;
    // 7
    // std::cout << reverseLoop("hola") << std::endl;
    // std::cout << reverse("hola") << std::endl;
    // 8
    // std::cout << palindromoLoop("massam") << std::endl;
    // string palabraPalindormo = "maassaam";
    // std::cout << palindromo(palabraPalindormo, palabraPalindormo.length() - 1) << std::endl;
    return 0;
}
