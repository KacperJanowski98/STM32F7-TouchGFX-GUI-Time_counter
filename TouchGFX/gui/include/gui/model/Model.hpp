#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void lps25hbMsgRdy();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
