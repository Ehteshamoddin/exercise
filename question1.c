#include <stdio.h>
#include <string.h>

void findAndReplace(char *input, const char *find, const char *replace)
{
    int inputLen = strlen(input);
    int findLen = strlen(find);
    int replaceLen = strlen(replace);

    for (int i = 0; i <= inputLen - findLen; i++)
    {
        int match = 1;
        for (int j = 0; j < findLen; j++)
        {
            if (input[i + j] != find[j])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            // Replace the matching substring
            for (int j = inputLen; j >= i + findLen; j--)
            {
                input[j + replaceLen - findLen] = input[j];
            }
            for (int j = 0; j < replaceLen; j++)
            {
                input[i + j] = replace[j];
            }
            i += replaceLen - 1;
            inputLen += replaceLen - findLen;
        }
    }
}

int main()
{
    char s1[31], s2[31], s3[31];

    // Input three sentences
    printf("Enter the first sentence: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Enter the second sentence: ");
    fgets(s2, sizeof(s2), stdin);
    printf("Enter the third sentence: ");
    fgets(s3, sizeof(s3), stdin);

    // Remove newline characters
    /* s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
    s3[strcspn(s3, "\n")] = '\0'; */

    // Perform find-and-replace operation
    findAndReplace(s1, s2, s3);

    // Print the final string
    printf("Final output: %s\n", s1);

    return 0;
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *before, char *oldsub, char *newsub);

int main()
{
    // test string
    char string[] = "this is";

    // try to replace the with that
    char *result = replace(string, "is", "bye");

    // output the before and after strings
    printf("before: %s\n", string);
    printf("after: %s\n", result);

    // free the memory allocated for the after string
    free(result);

    return 0;
}

// returns a pointer to a new after string that results from replacing all
// occurrences of the oldsub string in the before string with the newsub string
char *replace(char *before, char *oldsub, char *newsub)
{
    // get the lengths of the before string, old substring and new substring
    int old_length = strlen(oldsub);
    int new_length = strlen(newsub);
    int before_length = strlen(before);

    // stores pointer to the dynamically allocated after string
    char *after;

    // if the length of the old substring is the same as the new substring,
    // we can allocate space for the after string without doing any analysis
    // of the before string beforehand
    if (old_length == new_length)
    {
        // allocate the same amount of space for the after string as the before
        // string (the +1 is for the null terminator)
        after = malloc((before_length + 1) * sizeof(char));
    }
    // otherwise we need to figure out how many times does the old substring
    // occur in the before string, and use that information to allocate enough
    // space for the after string
    else
    {
        // keeps track of occurrences of the old substring in the before string
        int occurrences = 0;

        // use i as the current position in the before string and loop through
        // the string until we reach the end of the string
        int i = 0;
        while (i < before_length)
        {
            // if the first occurrence of the old substring in the before string
            // from index i onwards occurs at index i, then we have found an
            // occurrence of the substring at index i
            if (strstr(&before[i], oldsub) == &before[i])
            {
                // we increment the number of occurrences, and increment i by the
                // length of the old substring to skip over the old substring characters
                occurrences++;
                i += old_length;
            }
            // otherwise if we did not find an occurrence, increment i by 1 to check
            // for an occurrence at the next index
            else
                i++;
        }

        // calculate the difference between the new and old substring lengths
        int sub_diff = new_length - old_length;

        // use the before string's length as a starting point for the after
        // string's length
        int after_length = before_length;

        // and now adjust the after string's length by the number of occurrences
        // in the before string multipled by the difference in length between
        // the new substring and the old substring (and keep in mind if the new
        // substring is less length than the old substring, it will be negative
        // and as appropriate after_length will be less than before_length)
        after_length += occurrences * sub_diff;

        // allocate space for the after string, accounting for the null terminator
        after = malloc((after_length + 1) * sizeof(char));
    }

    // i will keep track of our current index in the before string
    int i = 0;

    // j will keep track of our current index in the after string that we will
    // now build
    int j = 0;

    // again we loop through the before string, just as above, but now we
    // will build the after string as we do so
    while (i < strlen(before))
    {
        // if the first occurrence of the old substring in the before string
        // from index i onwards occurs at index i, then we have found an
        // occurrence of the substring at index i
        if (strstr(&before[i], oldsub) == &before[i])
        {
            // we now copy into the after string AT INDEX J the new substring
            strcpy(&after[j], newsub);

            // we skip over old substring's amount of characters in the before string
            i += old_length;

            // but we add the new substring's amount of characters to j, because the
            // length of the old and new substring's may be different... j may be less
            // or more than i, but we'll use it to keep track of where we are writing
            // next into the after string
            j += new_length;
        }
        // if we did not find an occurrence of the old substring at index i in the
        // before string, we copy the next character from the before string into the
        // after string (using the respective variables), and we increment the
        // the indexes by 1 to move onto the next element in each array
        else
        {
            after[j] = before[i];
            i++;
            j++;
        }
    }

    // put a null terminator at the end of the after string
    after[j] = '\0';

    // return a pointer to the after string
    return after;
} */