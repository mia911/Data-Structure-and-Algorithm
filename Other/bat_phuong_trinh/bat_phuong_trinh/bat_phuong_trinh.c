if (x >= x1 && x >= x2) {
            if (x1 > x2) {
                printf("x > %f\n", x1);
            } else if (x2 > x1) {
                printf("x > %f\n", x2);
            } else if (x2 == x1) {
                printf("x > %f\n", x1);
            }
        } else if (x <= x1 && x <= x2) {
            if (x1 < x2) {
                printf("x < %f\n", x1);
            } else if (x2 < x1) {
                printf("x < %f\n", x2);
            } else if (x2 == x1) {
                printf("x < %f\n", x1);
            }
        } else if (x >= x1 && x <= x2) {
            if (x1 >= x2) {
                printf("There is no root for this equation.\n");
            } else if (x1 < x2) {
                printf("%f < x < %f", x1, x2);
            }
        } else if (x >= x2 && x <= x1) {
            if (x2 >= x1) {
                printf("There is no root for this equation.\n");
            } else if (x2 < x1) {
                printf("%f < x < %f", x2, x1);
            }
