#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace std;

sf::Texture X_texture,O_texture,BG_texture,board_texture,red_line_texture,longer_red_line_texture;
sf::Sprite background,board,red_line,longer_red_line;
sf::Text title,choose,playing_as_X,playing_as_O,you_win,you_lose,game_tie, play_again, yes, no;
sf::Font persona_font;
char board_state[3][3];
int board_logic[3][3], turn=0;

int load(sf::Sprite &X, sf::Sprite &O)
{
    if (!X_texture.loadFromFile("Resources/Transparent_X.png"))
        return 0;
    if (!O_texture.loadFromFile("Resources/Transparent_O.png"))
        return 0;
    if (!BG_texture.loadFromFile("Resources/White.png"))
        return 0;
    if (!board_texture.loadFromFile("Resources/board.png"))
        return 0;
    if (!persona_font.loadFromFile("Resources/earwig_factory.ttf"))
        return 0;
    if (!red_line_texture.loadFromFile("Resources/Red_line.png"))
        return 0;
    if (!longer_red_line_texture.loadFromFile("Resources/Longer_red_line.png"))
        return 0;
    X.setTexture(X_texture);
    O.setTexture(O_texture);
    background.setTexture(BG_texture);
    board.setTexture(board_texture);
    red_line.setTexture(red_line_texture);
    longer_red_line.setTexture(longer_red_line_texture);
    title.setFont(persona_font);
    title.setString("Auto Tic Tac Toe");
    title.setCharacterSize(60);
    title.setFillColor(sf::Color::Black);
    choose.setFont(persona_font);
    choose.setString("choose your mask");
    choose.setCharacterSize(30);
    choose.setFillColor(sf::Color::Black);
    playing_as_X.setFont(persona_font);
    playing_as_X.setString("You're playing as X");
    playing_as_X.setCharacterSize(30);
    playing_as_X.setFillColor(sf::Color::Black);
    playing_as_O.setFont(persona_font);
    playing_as_O.setString("You're playing as O");
    playing_as_O.setCharacterSize(30);
    playing_as_O.setFillColor(sf::Color::Black);
    you_win.setFont(persona_font);
    you_win.setString("YOU WIN");
    you_win.setCharacterSize(80);
    you_win.setFillColor(sf::Color::Green);
    you_lose.setFont(persona_font);
    you_lose.setString("YOU LOSE");
    you_lose.setCharacterSize(80);
    you_lose.setFillColor(sf::Color::Green);
    game_tie.setFont(persona_font);
    game_tie.setString("TIE");
    game_tie.setCharacterSize(80);
    game_tie.setFillColor(sf::Color::Green);
    play_again.setFont(persona_font);
    play_again.setString("PLAY AGAIN?");
    play_again.setCharacterSize(80);
    play_again.setFillColor(sf::Color::Green);
    yes.setFont(persona_font);
    yes.setString("YES");
    yes.setCharacterSize(80);
    yes.setFillColor(sf::Color::Green);
    no.setFont(persona_font);
    no.setString("NO");
    no.setCharacterSize(80);
    no.setFillColor(sf::Color::Green);
    return 1;
}

void draw_sprite(sf::RenderWindow &window, sf::Sprite sprite, int x, int y)
{
    switch (x)
    {
    case 0:
    {
        switch (y)
        {
        case 0:
        {
            sprite.setPosition(0,200);
            window.draw(sprite);
            return;
        }
        case 1:
        {
            sprite.setPosition(200,200);
            window.draw(sprite);
            return;
        }
        case 2:
        {
            sprite.setPosition(400,200);
            window.draw(sprite);
            return;
        }
        default:
            break;
        }
    }
    case 1:
    {
        switch (y)
        {
        case 0:
        {
            sprite.setPosition(0,400);
            window.draw(sprite);
            return;
        }
        case 1:
        {
            sprite.setPosition(200,400);
            window.draw(sprite);
            return;
        }
        case 2:
        {
            sprite.setPosition(400,400);
            window.draw(sprite);
            return;
        }
        default:
            break;
        }
    }
    case 2:
    {
        switch (y)
        {
        case 0:
        {
            sprite.setPosition(0,600);
            window.draw(sprite);
            return;
        }
        case 1:
        {
            sprite.setPosition(200,600);
            window.draw(sprite);
            return;
        }
        case 2:
        {
            sprite.setPosition(400,600);
            window.draw(sprite);
            return;
        }
        default:
            break;
        }
    }
    default:
        return;
    }
}

void receive_input(sf::RenderWindow &window, char &player_playing_as)
{
    sf::Event event;
    bool ok=0;
    while (!ok)
    {
        sf::sleep(sf::milliseconds(1));
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button==sf::Mouse::Left)
                {
                    int x=event.mouseButton.x,y=event.mouseButton.y;
                    if (x>=0&&x<=200)
                    {
                        if (y>=200&&y<=400)
                        {
                            if (!board_state[0][0])
                            {
                                board_state[0][0]=player_playing_as;
                                if (player_playing_as=='O') board_logic[0][0]=-1;
                                else board_logic[0][0]=1;
                                ok=1;
                            }
                        }
                        else if(y>=400&&y<=600)
                        {
                            if (!board_state[1][0])
                            {
                                board_state[1][0]=player_playing_as;
                                if (player_playing_as=='O') board_logic[1][0]=-1;
                                else board_logic[1][0]=1;
                                ok=1;
                            }
                        }
                        else if (y>=600&&y<=800)
                        {
                            if (!board_state[2][0])
                            {
                                board_state[2][0]=player_playing_as;
                                if (player_playing_as=='O') board_logic[2][0]=-1;
                                else board_logic[2][0]=1;
                                ok=1;
                            }
                        }
                    }
                    else if (x>=200&&x<=400)
                    {
                        if (y>=200&&y<=400)
                        {
                            if (!board_state[0][1])
                            {
                                board_state[0][1]=player_playing_as;
                                if (player_playing_as=='O') board_logic[0][1]=-1;
                                else board_logic[0][1]=1;
                                ok=1;
                            }
                        }
                        else if(y>=400&&y<=600)
                        {
                            if (!board_state[1][1])
                            {
                                board_state[1][1]=player_playing_as;
                                if (player_playing_as=='O') board_logic[1][1]=-1;
                                else board_logic[1][1]=1;
                                ok=1;
                            }
                        }
                        else if (y>=600&&y<=800)
                        {
                            if (!board_state[2][1])
                            {
                                board_state[2][1]=player_playing_as;
                                if (player_playing_as=='O') board_logic[2][1]=-1;
                                else board_logic[2][1]=1;
                                ok=1;
                            }
                        }
                    }
                    else if (x>=400&&x<=600)
                    {
                        if (y>=200&&y<=400)
                        {
                            if (!board_state[0][2])
                            {
                                board_state[0][2]=player_playing_as;
                                if (player_playing_as=='O') board_logic[0][2]=-1;
                                else board_logic[0][2]=1;
                                ok=1;
                            }
                        }
                        else if(y>=400&&y<=600)
                        {
                            if (!board_state[1][2])
                            {
                                board_state[1][2]=player_playing_as;
                                if (player_playing_as=='O') board_logic[1][2]=-1;
                                else board_logic[1][2]=1;
                                ok=1;
                            }
                        }
                        else if (y>=600&&y<=800)
                        {
                            if (!board_state[2][2])
                            {
                                board_state[2][2]=player_playing_as;
                                if (player_playing_as=='O') board_logic[2][2]=-1;
                                else board_logic[2][2]=1;
                                ok=1;
                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
                throw "nbu";
            }
        }
    }
}

void choose_mask(sf::RenderWindow &window, char &player_playing_as, sf::Sprite &X, sf::Sprite &O)
{
    sf::Event event;
    while (!player_playing_as)
    {
        sf::sleep(sf::milliseconds(1));
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button==sf::Mouse::Left)
                {
                    int x=event.mouseButton.x,y=event.mouseButton.y;
                    if (x>=X.getPosition().x&&x<=X.getPosition().x+190&&y>=X.getPosition().y&&y<=X.getPosition().y+190)
                    {
                        player_playing_as='X';
                        break;
                    }
                    if(x>=O.getPosition().x&&x<=O.getPosition().x+190&&y>=O.getPosition().y&&y<=O.getPosition().y+190)
                    {
                        player_playing_as='O';
                        break;
                    }
                }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
                throw "nbu";
            }
        }
    }
}

int check_game_over(int temp_board[3][3], int &who_won)
{
    for (int i=0; i<3; i++)
    {
        if(temp_board[i][0]==temp_board[i][1]&&temp_board[i][0]==temp_board[i][2]&&temp_board[i][0]&&temp_board[i][1]&&temp_board[i][2])
        {
            who_won=temp_board[i][0];
            return i+1;
        }
        if(temp_board[0][i]==temp_board[1][i]&&temp_board[0][i]==temp_board[2][i]&&temp_board[0][i]&&temp_board[1][i]&&temp_board[2][i])
        {
            who_won=temp_board[0][i];
            return i+4;
        }
    }
    if(temp_board[0][0]==temp_board[1][1]&&temp_board[0][0]==temp_board[2][2]&&temp_board[0][0]&&temp_board[1][1]&&temp_board[2][2])
    {
        who_won=temp_board[0][0];
        return 7;
    }
    if(temp_board[0][2]==temp_board[1][1]&&temp_board[0][2]==temp_board[2][0]&&temp_board[0][2]&&temp_board[1][1]&&temp_board[2][0])
    {
        who_won=temp_board[0][2];
        return 8;
    }
    int ok=1;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (!temp_board[i][j]) ok=0;
    if (ok) return 9;
    return 0;
}

void choose_random_edge(int &x, int &y)
{
    srand(time(NULL));
    int edge=rand()%4;
    switch(edge)
    {
    case 0:
    {
        x=0;
        y=1;
        break;
    }
    case 1:
    {
        x=1;
        y=2;
        break;
    }
    case 2:
    {
        x=2;
        y=1;
        break;
    }
    case 3:
    {
        x=1;
        y=0;
        break;
    }
    default:
        break;
    }
}

void choose_random_colt(int &x, int &y)
{
    srand(time(NULL));
    int edge=rand()%4;
    switch(edge)
    {
    case 0:
    {
        x=0;
        y=0;
        break;
    }
    case 1:
    {
        x=2;
        y=0;
        break;
    }
    case 2:
    {
        x=0;
        y=2;
        break;
    }
    case 3:
    {
        x=2;
        y=2;
        break;
    }
    default:
        break;
    }
}

void think_v2(char &player_playing_as)
{
    int decided=0,x,y,temp_who_wins;
    if (player_playing_as=='X')
    {
        if (turn==1&&!decided)
        {
            if (!board_state[1][1])
            {
                x=1;
                y=1;
                decided=1;
            }
            else
            {
                choose_random_colt(x,y);
                decided=1;
            }
        }
        for (int i=0; i<3&&!decided; i++)
        {
            for (int j=0; j<3&&!decided; j++)
            {
                if (!board_logic[i][j])
                {
                    board_logic[i][j]=-1;
                    if (check_game_over(board_logic,temp_who_wins))
                    {
                        x=i;
                        y=j;
                        decided=1;
                    }
                    board_logic[i][j]=0;
                }
            }
        }
        for (int i=0; i<3&&!decided; i++)
        {
            for (int j=0; j<3&&!decided; j++)
            {
                if (!board_logic[i][j])
                {
                    board_logic[i][j]=1;
                    if (check_game_over(board_logic,temp_who_wins))
                    {
                        x=i;
                        y=j;
                        decided=1;
                    }
                    board_logic[i][j]=0;
                }
            }
        }
        if (turn==3&&!decided)
        {
            if (!board_logic[0][0]&&!board_logic[0][2]&&!board_logic[2][0]&&!board_logic[2][2])
            {
                int smax=0;
                if (!board_logic[0][0])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[0][i];
                        s+=board_logic[i][0];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=0;
                        y=0;
                    }
                }
                if (!board_logic[0][2])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[0][i];
                        s+=board_logic[i][2];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=0;
                        y=2;
                    }
                }
                if (!board_logic[2][0])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[2][i];
                        s+=board_logic[i][0];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=2;
                        y=0;
                    }
                }
                if (!board_logic[2][2])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[2][i];
                        s+=board_logic[i][2];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=2;
                        y=2;
                    }
                }
                decided=1;
            }
            else
            {
                if (board_logic[1][1] == -1) {
                    while (!decided)
                    {
                        choose_random_edge(x, y);
                        if (!board_state[x][y]) decided = 1;
                    }
                }
                else
                {
                    while (!decided)
                    {
                        choose_random_colt(x, y);
                        if (!board_state[x][y]) decided = 1;
                    }
                }
            }
        }
        while (!decided)
        {
            choose_random_colt(x,y);
            if (!board_state[x][y])
            {
                decided=1;
                break;
            }
            choose_random_edge(x,y);
            if (!board_state[x][y]) decided=1;
        }
        board_state[x][y]='O';
        board_logic[x][y]=-1;
    }
    else
    {
        for (int i=0; i<3&&!decided; i++)
        {
            for (int j=0; j<3&&!decided; j++)
            {
                if (!board_logic[i][j])
                {
                    board_logic[i][j]=1;
                    if (check_game_over(board_logic,temp_who_wins))
                    {
                        x=i;
                        y=j;
                        decided=1;
                    }
                    board_logic[i][j]=0;
                }
            }
        }
        for (int i=0; i<3&&!decided; i++)
        {
            for (int j=0; j<3&&!decided; j++)
            {
                if (!board_logic[i][j])
                {
                    board_logic[i][j]=-1;
                    if (check_game_over(board_logic,temp_who_wins))
                    {
                        x=i;
                        y=j;
                        decided=1;
                    }
                    board_logic[i][j]=0;
                }
            }
        }
        if (turn==2&&!decided)
        {
            if (board_logic[1][1])
            {
                for (int i=0; i<3; i++)
                    for (int j=0; j<3; j++)
                        if (board_logic[i][j]==1)
                        {
                            x=2-i;
                            y=2-j;
                            decided=1;
                        }
            }
            else
            {
                int smax=0;
                if (!board_logic[0][0])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[0][i];
                        s+=board_logic[i][0];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=0;
                        y=0;
                    }
                }
                if (!board_logic[0][2])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[0][i];
                        s+=board_logic[i][2];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=0;
                        y=2;
                    }
                }
                if (!board_logic[2][0])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[2][i];
                        s+=board_logic[i][0];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=2;
                        y=0;
                    }
                }
                if (!board_logic[2][2])
                {
                    int s=0;
                    for (int i=0; i<3; i++)
                    {
                        s+=board_logic[2][i];
                        s+=board_logic[i][2];
                    }
                    if (s>=smax)
                    {
                        smax=s;
                        x=2;
                        y=2;
                    }
                }
                decided=1;
            }
        }
        if (turn==4&&!decided)
        {
            int smax=0;
            if (!board_logic[0][0])
            {
                int s=0;
                for (int i=0; i<3; i++)
                {
                    s+=board_logic[0][i];
                    s+=board_logic[i][0];
                }
                if (s>=smax)
                {
                    smax=s;
                    x=0;
                    y=0;
                }
            }
            if (!board_logic[0][2])
            {
                int s=0;
                for (int i=0; i<3; i++)
                {
                    s+=board_logic[0][i];
                    s+=board_logic[i][2];
                }
                if (s>=smax)
                {
                    smax=s;
                    x=0;
                    y=2;
                }
            }
            if (!board_logic[2][0])
            {
                int s=0;
                for (int i=0; i<3; i++)
                {
                    s+=board_logic[2][i];
                    s+=board_logic[i][0];
                }
                if (s>=smax)
                {
                    smax=s;
                    x=2;
                    y=0;
                }
            }
            if (!board_logic[2][2])
            {
                int s=0;
                for (int i=0; i<3; i++)
                {
                    s+=board_logic[2][i];
                    s+=board_logic[i][2];
                }
                if (s>=smax)
                {
                    smax=s;
                    x=2;
                    y=2;
                }
            }
            decided=1;
        }
        board_state[x][y]='X';
        board_logic[x][y]=1;
    }
}

void restart_game(char &player_playing_as, int &started, int &skip_first_turn_as_O, int &game_status, int &playing, int &who_won)
{
    player_playing_as=0;
    started=0;
    skip_first_turn_as_O=0;
    game_status=0;
    playing=1;
    who_won=0;
    turn=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            board_logic[i][j]=0;
            board_state[i][j]=0;
        }
}

void choose_replay(int &playing, sf::RenderWindow &window)
{
    sf::Event event;
    int ok=0;
    while (!ok)
    {
        sf::sleep(sf::milliseconds(1));
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button==sf::Mouse::Left)
                {
                    int x=event.mouseButton.x,y=event.mouseButton.y;
                    if (x>=yes.getPosition().x&&x<=yes.getPosition().x+140&&y>=yes.getPosition().y&&y<=yes.getPosition().y+150)
                    {
                        playing=1;
                        ok=1;
                        break;
                    }
                    if(x>=no.getPosition().x&&x<=no.getPosition().x+100&&y>=no.getPosition().y&&y<=no.getPosition().y+150)
                    {
                        playing=0;
                        ok=1;
                        break;
                    }
                }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
                throw "nbu";
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Auto Tic Tac Toe v1.3");
    char player_playing_as=0;
    int started=0,skip_first_turn_as_O=0,game_status=0,playing=1,who_won=0;
    sf::Sprite X,O;
    if (!load(X,O))
        return -1;
    while (window.isOpen()&&playing)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
        window.clear();
        window.draw(background);
        title.setPosition(14,5);
        window.draw(title);
        if (player_playing_as)
        {
            board.setPosition(0,200);
            window.draw(board);
            window.display();
            while (!game_status)
            {
                sf::sleep(sf::milliseconds(1));
                window.clear();
                window.draw(background);
                title.setPosition(14,5);
                window.draw(title);
                board.setPosition(0,200);
                window.draw(board);
                if (player_playing_as=='X')
                {
                    playing_as_X.setPosition(135,115);
                    window.draw(playing_as_X);
                }
                else
                {
                    playing_as_O.setPosition(135,115);
                    window.draw(playing_as_O);
                }
                if (!started)
                {
                    int x,y;
                    choose_random_colt(x,y);
                    board_state[x][y]='X';
                    board_logic[x][y]=1;
                    started=1;
                    turn++;
                }
                if (skip_first_turn_as_O)
                {
                    think_v2(player_playing_as);
                    turn++;
                }
                else skip_first_turn_as_O=1;
                game_status=check_game_over(board_logic,who_won);
                if (game_status) break;
                for (int i=0; i<3; i++)
                    for (int j=0; j<3; j++)
                    {
                        if(board_state[i][j]=='X')
                            draw_sprite(window,X,i,j);
                        else if (board_state[i][j]=='O')
                            draw_sprite(window,O,i,j);
                    }
                window.display();
                receive_input(window, player_playing_as);
                turn++;
                game_status=check_game_over(board_logic,who_won);
                if (game_status) break;
                for (int i=0; i<3; i++)
                    for (int j=0; j<3; j++)
                    {
                        if(board_state[i][j]=='X')
                            draw_sprite(window,X,i,j);
                        else if (board_state[i][j]=='O')
                            draw_sprite(window,O,i,j);
                    }
                window.display();
            }
        }
        else
        {
            choose.setPosition(165,200);
            window.draw(choose);
            X.setPosition(210,300);
            window.draw(X);
            O.setPosition(210,550);
            window.draw(O);
            window.display();
            choose_mask(window, player_playing_as,X,O);
            if (player_playing_as=='X') started=1;
        }
        if (player_playing_as=='X')
        {
            playing_as_X.setPosition(135,115);
            window.draw(playing_as_X);
        }
        else
        {
            playing_as_O.setPosition(135,115);
            window.draw(playing_as_O);
        }
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
            {
                if(board_state[i][j]=='X')
                    draw_sprite(window,X,i,j);
                else if (board_state[i][j]=='O')
                    draw_sprite(window,O,i,j);
            }
        switch (game_status)
        {
        case 1:
        {
            red_line.setPosition(0,295);
            window.draw(red_line);
            break;
        }
        case 2:
        {
            red_line.setPosition(0,495);
            window.draw(red_line);
            break;
        }
        case 3:
        {
            red_line.setPosition(0,695);
            window.draw(red_line);
            break;
        }
        case 4:
        {
            red_line.setRotation(90);
            red_line.setPosition(100,200);
            window.draw(red_line);
            break;
        }
        case 5:
        {
            red_line.setRotation(90);
            red_line.setPosition(300,200);
            window.draw(red_line);
            break;
        }
        case 6:
        {
            red_line.setRotation(90);
            red_line.setPosition(500,200);
            window.draw(red_line);
            break;
        }
        case 7:
        {
            longer_red_line.setRotation(45);
            longer_red_line.setPosition(13,205);
            window.draw(longer_red_line);
            break;
        }
        case 8:
        {
            longer_red_line.setRotation(135);
            longer_red_line.setPosition(590,205);
            window.draw(longer_red_line);
            break;
        }
        case 9:
        {
            game_tie.setPosition(220,250);
            window.draw(game_tie);
            break;
        }
        }
        switch (who_won)
        {
        case 1:
        {
            if (player_playing_as=='X')
            {
                you_win.setPosition(115,250);
                window.draw(you_win);
            }
            else
            {
                you_lose.setPosition(90,250);
                window.draw(you_lose);
            }
            break;
        }
        case -1:
        {
            if (player_playing_as=='X')
            {
                you_lose.setPosition(90,250);
                window.draw(you_lose);
            }
            else
            {
                you_win.setPosition(115,250);
                window.draw(you_win);
            }
            break;
        }
        default:
            break;
        }
        if (game_status)
        {
            play_again.setPosition(30,450);
            window.draw(play_again);
            yes.setPosition(120,600);
            window.draw(yes);
            no.setPosition(350,600);
            window.draw(no);
            window.display();
            choose_replay(playing,window);
            if (playing) restart_game(player_playing_as, started, skip_first_turn_as_O, game_status, playing, who_won);
            else return 0;
        }
    }
    return 0;
}
