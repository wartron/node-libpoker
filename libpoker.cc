#include <node.h>
#include <v8.h>

//#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "poker_defs.h"
#include "inlines/eval.h"

using namespace v8;

// Tidies up user input for a hand
void    cleanInput(char *hand) {
    int i = 0;

    while (hand[i] != 0) {
        if (hand[i] == '\n') {
            hand[i] = 0;
            break;
        }

        if (i%2 == 0)
            hand[i] = toupper(hand[i]);
        else
            hand[i] = tolower(hand[i]);

        i++;
    }
}
// Converts plaintext to cardmask
StdDeck_CardMask    txtToMask(const char *txt) {
    StdDeck_CardMask    hand;       // the hand to return
    StdDeck_CardMask    currCard;   // current card mask
    int                 index;      // tmp card index valie
    char                card[3];
    int                 i = 0;

    StdDeck_CardMask_RESET(hand);

    if (strlen(txt)) {
        while (txt[i*2] != 0) {
            card[0] = txt[0+i*2];
            card[1] = txt[1+i*2];
            card[2] = 0;

            // convert card to index value
            StdDeck_stringToCard(card, &index);
            // convert index value to mask
            currCard = StdDeck_MASK(index);
            // add the card to the hand
            StdDeck_CardMask_OR(hand, hand, currCard);
            // move to next card
            i++;
        }
    }

    return hand;
}




Handle<Value> funScore(const Arguments& args) {
    HandleScope scope;

    char                hand1str[10];
    char                hand2str[10];
    char                boardstr[10];
    StdDeck_CardMask    hand1, hand2, board;

    //StdDeck_CardMask_RESET(board);

    sprintf(hand1str,"KdQd");
    cleanInput(hand1str);
    hand1 = txtToMask(hand1str);

    sprintf(hand2str,"1d2d");
    cleanInput(hand2str);
    hand2 = txtToMask(hand2str);

    sprintf(boardstr,"Jd0d9d8d7d");
    cleanInput(boardstr);
    board = txtToMask(boardstr);




    return scope.Close(String::New("world"));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("score"),
        FunctionTemplate::New(funScore)->GetFunction());
}

NODE_MODULE(poker, init)  /////////// FUCK! WHY DOES THIS STRIP THE lib PART of libpoker
