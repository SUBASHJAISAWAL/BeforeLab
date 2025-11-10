package see;

import cie.*;

public class External extends Student {
    public int seeMarks[] = new int[5];

    public void setSEEMarks(int marks[]) {
        for (int i = 0; i < 5; i++) {
            seeMarks[i] = marks[i];
        }
    }
}

