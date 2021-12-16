/*Both source and target are linked lists that are initialized by the caller.
The end of list is market by setting next pointer of the last element to NULL.*/

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
