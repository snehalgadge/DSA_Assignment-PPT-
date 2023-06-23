/*<aside>
💡 **Question 3**

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers `0` and `1` respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a **stack**. At each step:

- If the student at the front of the queue **prefers** the sandwich on the top of the stack, they will **take it** and leave the queue.
- Otherwise, they will **leave it** and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays `students` and `sandwiches` where `sandwiches[i]` is the type of the `ith` sandwich in the stack (`i = 0` is the top of the stack) and `students[j]` is the preference of the `jth` student in the initial queue (`j = 0` is the front of the queue). Return *the number of students that are unable to eat.*

</aside>*/

// SOLUTION
int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> student_choice;
        for(int i = 0 ; i < size ; ++i){
            student_choice.push(students[i]);
        }
        int rotations = 0 , i = 0;
        while(student_choice.size() && rotations < student_choice.size()){
            if(student_choice.front() == sandwiches[i]){
                student_choice.pop();
                i++;
                rotations = 0;
            } else {
                int choice = student_choice.front();
                student_choice.pop();
                student_choice.push(choice);
                rotations++;
            }
        }
        return student_choice.size();
    }