int move(student **source, int group, student **target) {
    int count = 0;
    while(*source != NULL) {
        if((*source)->group == group) {
            student *temp = *source;
            *source = temp->next;
            temp->next = *target;
            *target = temp;
            count++;
        }else {
            source = &(*source)->next;
        }
    }
    return count;
}
