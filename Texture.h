//
// Created by rostard on 17.12.17.
//

#ifndef DORMENGINE_TEXTURE_H
#define DORMENGINE_TEXTURE_H


class Texture {
public:
    Texture(int id);
    Texture();

    void bind();

    int getId(){
        return id;
    }
private:
    int id;
};


#endif //DORMENGINE_TEXTURE_H
