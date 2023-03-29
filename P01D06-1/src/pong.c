#include <math.h>

#include "stdio.h"
void draw(int p_left, int p_right, int ball_x, int ball_y, int right_points, int left_points) {
    printf(
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"
        "■■■■■■■■■■■■\n");
    for (int y = 0; y < 26; y++) {
        for (int x = 0; x <= 80; x++) {
            if (x == 0) {
                printf("■");
            } else if (x == 80) {
                printf("■\n");
            } else if ((y == p_left || y == p_left + 1 || y == p_left - 1) && (x == 4)) {
                printf("│");
            } else if ((y == p_right || y == p_right + 1 || y == p_right - 1) && (x == 80 - 4)) {
                printf("│");
            } else if (x == ball_x && y == ball_y) {
                printf("*");
            } else if (x == 40) {
                printf("│");
            } else if (x == 35 && y == 5) {
                printf("%d", left_points);
            } else if (x == 45 && y == 5) {
                printf("%d", right_points);
            } else {
                printf(" ");
            }
        }
    }
    printf(
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"
        "■■■■■■■■■■■■\n");
}
int move_left(char move, int pos) {
    if (move == 'z' && pos < 24) {
        return 1;
    } else if (move == 'a' && pos > 1) {
        return -1;
    } else if (move == ' ') {
        return 0;
    }
    return 0;
}
int move_right(char move, int pos) {
    if (move == 'm' && pos < 24) {
        return 1;
    } else if (move == 'k' && pos > 1) {
        return -1;
    } else if (move == ' ') {
        return 0;
    }
    return 0;
}
int ball_collision_y(int ball_y, int ball_move_y) {
    if (ball_y == 25) {
        return -ball_move_y;
    } else if (ball_y == 0) {
        return -ball_move_y;
    }
    return ball_move_y;
}

int ball_collision_x(int ball_x, int ball_y, int ball_move_x, int p_left, int p_right) {
    if (ball_x == 80) {
        return 2;
    } else if (ball_x == 0) {
        return 3;
    }
    if ((ball_x == 5 || ball_x == 80 - 5) &&
        (ball_y == p_left || ball_y == p_left + 1 || ball_y == p_left - 1 || ball_y == p_right ||
         ball_y == p_right + 1 || ball_y == p_right - 1)) {
        return -ball_move_x;
    }
    return ball_move_x;
}
int main() {
    int p_left = 13, p_right = 13, left_points = 0, right_points = 0;
    int ball_x = 40, ball_y = 13, ball_move_x = 1, ball_move_y = 1;
    char move_key;
    draw(p_left, p_right, ball_x, ball_y, right_points, left_points);
    while (left_points < 21 && right_points < 21) {
        move_key = getchar();
        if (move_key == 'k' || move_key == 'm' || move_key == 'a' || move_key == 'z' || move_key == ' ') {
            p_left = p_left + move_left(move_key, p_left);
            p_right = p_right + move_right(move_key, p_right);

            // ball move
            ball_x = ball_x + ball_move_x;
            ball_y = ball_y + ball_move_y;
            ball_move_y = ball_collision_y(ball_y, ball_move_y);
            if (ball_collision_x(ball_x, ball_y, ball_move_x, p_left, p_right) == 2) {
                left_points++;
                ball_x = 40;
                ball_y = 13;
                ball_move_x = -ball_move_x;
            } else if (ball_collision_x(ball_x, ball_y, ball_move_x, p_left, p_right) == 3) {
                right_points++;
                ball_x = 40;
                ball_y = 13;
                ball_move_x = -ball_move_x;
            } else {
                ball_move_x = ball_collision_x(ball_x, ball_y, ball_move_x, p_left, p_right);
            }

            // ball move
            draw(p_left, p_right, ball_x, ball_y, right_points, left_points);
        }
    }
    if (left_points > right_points) {
        printf("ЛЕВЫЙ ИГРОК ПОБЕДИЛ");
    } else {
        printf("ПРАВЫЙ ИГРОК ПОБЕДИЛ");
    }
    return 0;
}