rintf("Enter ID of student %d: ", i + 1);
        scanf("%d", &AA[i]);
    }

    // Insertion sort
    for (int i = 1; i < size; i++) {
        int key = AA[i];
        char key_name[30];
        strcpy(key_name, name[i]);
        int j = i - 1;

        // Move elements of AA[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && AA[j] > key) {
            AA[j + 1] = AA[j];
            strcpy(name[j + 1], name[j]);
            j = j - 1;
        }
        AA[j + 1] = key;
        strcpy(name[j + 1], key_name);
    }

    printf("\nSorted values : \n\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", AA[i], name[i]);
    }

    return 0;
}