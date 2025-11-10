package cie;

public class Internals extends Student {
    public int internalMarks[] = new int[5];

    public void setInternalMarks(int marks[]) {
        for (int i = 0; i < 5; i++) {
            internalMarks[i] = marks[i];
        }
    }
}

