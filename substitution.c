#include <stdio.h>
#include <string.h>

#include <cs50.h>


int is_key_valid(int length, string argv[]);
void print_errors(int error_code);
void cipher(string plaintext, string key);
bool is_uppercase(int asciicode);
bool is_lowercase(int asciicode);

int main(int argc, string argv[])
{
    int validity = is_key_valid(argc, argv);

    //if key is valid
    //3 : ok / 2, 1, 0 : not ok
    if (validity == 3)
    {

        string plain_text = get_string("plaintext: ");
        
        //encode plain text
        cipher(plain_text, argv[1]);
    }
    else
    {
        print_errors(validity);
        return 1;
    }

    return 0;
}

void cipher(string plaintext, string key)
{

    int length = strlen(plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < length; i++)
    {
        char single_char = plaintext[i];
        int index = 0;

        if (is_uppercase(single_char))
        {
            index = single_char - 65;

            if (is_lowercase(key[index]))
            {
                //replace character by the character at the same index in key
                //c is 3rd letter in alphabet : replaced by key[2] (0 based)
                
                single_char = key[index] - 32;
            }
            else
            {
                single_char = key[index];
            }
        }
        else if (is_lowercase(single_char))
        {
            index = single_char - 97;

            if (is_uppercase(key[index]))
            {
                single_char = key[index] + 32;
            }
            else 
            {
                single_char = key[index];
            }
        }
        else
        {
            single_char = plaintext[i];
        }

        printf("%c", single_char);
    }

    printf("\n");
}

bool is_uppercase(int asciicode)
{
    if (asciicode >= 65 && asciicode <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_lowercase(int asciicode)
{
    if (asciicode >= 97 && asciicode <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int is_key_valid(int length, string argv[])
{
    //2 : all ok / 1: key length not ok / 0 nb args not ok
    if (length == 2)
    {
        string key = argv[1];

        int key_length = (int)strlen(key);

        if (key_length == 26)
        {
            //for every character
            for (int i = 0; i < key_length; i++)
            {
                if (is_lowercase(key[i]) || is_uppercase(key[i]))
                {
                    //compare it to all characters
                    for (int j = 0; j < key_length; j++)
                    {
                        //if the character is not itself (same index)
                        if (j != i)
                        {
                            //we have a duplicate
                            if (key[j] == key[i]) 
                            {
                                return 2;
                            }
                        }
                    }
                }
                else 
                {
                    return 2;
                }
            }
            // printf("%s\n", key);
            // else, everything seems ok with the key (number of parameters ok, good length, no duplicate characters)
            return 3;
        }
        else
        {
            // length not ok
            return 1;
        }
    }
    else
    {
        // number of parameters not ok
        return 0;
    }
}

void print_errors(int error_code)
{
    if (error_code == 1)
    {
        // length not ok
        printf("Key must contain 26 characters.\n");
    }
    else if (error_code == 0)
    {
        // number of parameters not ok
        printf("Usage: ./substitution key\n");
    }
    else if (error_code == 2) 
    {
        //duplicate or forbidden char
        printf("Duplicate char in key or forbidden character\n");
    }
}