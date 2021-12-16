void sort_students(student *students, int count, sort_order sb) {
    int total;
    for (total = 0; students[total].id != 0; total++);
    int (*compare[])(const void* a, const void* b) = {group, last, first};
    if (count <= 0) {
        qsort(students, total, sizeof(student), compare[sb]);
    } else {
        qsort(students, count, sizeof(student), compare[sb]);
    }
}

int group(const void* a, const void* b) {
    int l = ((student*)a)->group;
    int r = ((student*)b)->group;
    return (l - r);
}


int first(const void* a, const void* b) {
    char l[MAX_LEN];
    char r[MAX_LEN];
    char name[MAX_LEN] = "something";
    sscanf(((student*)a)->name, "%s", l);
    sscanf(((student*)b)->name, "%s", r);
    if (strcmp(l,r) == 0) {
        sscanf(((student*)a)->name,"%*s %s",l);
        sscanf(((student*)b)->name,"%*s %s",r); 
    }
    return strcmp(l,r);
} 

int last(const void* a, const void* b) {
    char l[MAX_LEN];
    char r[MAX_LEN];
    sscanf(((student*)a)->name,"%*s %s",l);
    sscanf(((student*)b)->name,"%*s %s",r);
    return strcmp(l,r);
}  
