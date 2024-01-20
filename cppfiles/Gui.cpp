#include "../headers/stdafx.h"
#include "../headers/Gui.h"

const float gui::p2pX(const float perc, const sf::VideoMode& vm)
{
    return std::floor(static_cast<float>(vm.width) * (perc / 100.f));
}

const float gui::p2pY(const float perc, const sf::VideoMode& vm)
{
    return std::floor(static_cast<float>(vm.height) * (perc / 100.f));
}

const unsigned gui::calcCharSize(const sf::VideoMode& vm, const unsigned modifier)
{
    return static_cast<unsigned>((vm.width + vm.height) / modifier);
}

sf::ConvexShape gui::Button::createParallelogram(float x, float y, float width, float height, float angle) {
    sf::ConvexShape parallelogram;

    float radianAngle = angle * (3.14159265f / 180.f);
    float deltaX = height * cos(radianAngle);
    float deltaY = height * sin(radianAngle);

    sf::Vector2f point1(x, y);
    sf::Vector2f point2(x + width, y);
    sf::Vector2f point3(x + width + deltaX, y + deltaY);
    sf::Vector2f point4(x + deltaX, y + deltaY);

    parallelogram.setPointCount(4);
    parallelogram.setPoint(0, point1);
    parallelogram.setPoint(1, point2);
    parallelogram.setPoint(2, point3);
    parallelogram.setPoint(3, point4);


    return parallelogram;
}


gui::Button::Button(float x, float y, float width, float height,
                    sf::Font* font, std::string text, unsigned character_size,
                    sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
                    sf::Color idle_color, sf::Color hover_color, sf::Color active_color, ShapeType shapeType,
                    short unsigned id, Animation* bg, float angle)
        : buttonState(BTN_IDLE), id(id), bg(bg), shapeType(shapeType)
{
    this->buttonState = BTN_IDLE;
    this->id = id;
    this->bg = bg;

    if (this->shapeType == RECTANGLE) {
        this->rectangleShape.setPosition(sf::Vector2f(x, y));
        this->rectangleShape.setSize(sf::Vector2f(width, height));
        shape = &rectangleShape;
    } else if (this->shapeType == PARALLELOGRAM) {
        this->parallelogramShape = createParallelogram(x, y, width, height, angle);
        shape = &parallelogramShape;
    } else {
        this->rectangleShape.setPosition(sf::Vector2f(x, y));
        this->rectangleShape.setSize(sf::Vector2f(width, height));
        shape = &rectangleShape;
    }

    if (bg == nullptr) {
        this->shape->setOutlineThickness(1.f);
    }

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_idle_color);
    this->text.setCharacterSize(character_size);

    this->text.setPosition(
            this->shape->getPosition().x + (this->shape->getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape->getPosition().y + (this->shape->getGlobalBounds().height / 4.f) - this->text.getGlobalBounds().height / 4.f
    );

    this->textIdleColor = text_idle_color;
    this->textHoverColor = text_hover_color;
    this->textActiveColor = text_active_color;

    this->idleColor = idle_color;
    this->hoverColor = hover_color;
    this->activeColor = active_color;
}


gui::Button::~Button()
{
}

//	Accessors
const bool gui::Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE) {
        return true;
    }
    return false;
}

const short unsigned & gui::Button::getId() const
{
    return this->id;
}

//	Functions
void gui::Button::update(const sf::Vector2i& mousePosWindow)
{
    /* Update the booleans for hover and pressed */

    //	Idle
    this->buttonState = BTN_IDLE;
    //	Hover

    if (this->shape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow))) {
        this->buttonState = BTN_HOVER;
        //	Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
        case BTN_IDLE:
            this->shape->setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);

            break;
        case BTN_HOVER:
            this->shape->setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);

            break;
        case BTN_ACTIVE:
            this->shape->setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
            break;
        default:
            this->shape->setFillColor(sf::Color::Red);
            this->shape->setOutlineColor(sf::Color::Green);
            this->text.setFillColor(sf::Color::Blue);
            break;
    }

}

void gui::Button::render(sf::RenderTarget & target)
{
    if (bg != nullptr) {
        shape->setTexture(bg->getAnim(), true);

        // Check the shape type and handle accordingly
        if (shapeType == PARALLELOGRAM) {
            // Set texture coordinates based on the shape's points
            sf::Vector2f textureCoords[4];
            for (unsigned int i = 0; i < 4; ++i) {
                textureCoords[i] = shape->getTransform().transformPoint(shape->getPoint(i));
            }

            // Create a vertex array to store the shape with texture coordinates
            sf::VertexArray vertices(sf::Quads, 4);
            for (unsigned int i = 0; i < 4; ++i) {
                vertices[i].position = shape->getPoint(i);
                vertices[i].texCoords = textureCoords[i];
            }

            // Draw the textured shape using RenderStates
            sf::RenderStates states;
            states.texture = bg->getAnim();
            target.draw(vertices, states);
        } else {
            // For other shape types, draw the shape without custom texture coordinates
            target.draw(*shape);
        }
    }
    target.draw(*shape);

    target.draw(this->text);
}



//	LoadingScreen

gui::LoadingScreen::LoadingScreen()
{
        this->container.setSize(sf::Vector2f(1920,1080));
        loadingAnim=new Animation();
    loadingAnim->loadAnimation("../Resources/Images/loadinganim/tile000.png", 41, sf::Vector2f(800.f, 800.f));
}

gui::LoadingScreen::~LoadingScreen()
{

}

//	Accessors

//	Functions
void gui::LoadingScreen::startRender(sf::RenderTarget & target){
    if(index>0){
        container.setTexture(loadingAnim->getAnimIndex(index));
        target.draw(container);
        index--;
    }else{
        animIsFinish=true;
    }
}



void gui::LoadingScreen::render(sf::RenderTarget & target)
{
    if(index<=40){
        container.setTexture(loadingAnim->getAnimIndex(index));
        target.draw(container);
        index++;
    }else{
        animIsFinish=true;
    }

}

bool gui::LoadingScreen::getAnimIsFinish() {
    return animIsFinish;
}

void gui::LoadingScreen::setStartPositionIndex() {
    index=40;
}

void gui::LoadingScreen::setEndPositionIndex() {
    index=0;
}

void gui::LoadingScreen::setAnimIsFinish(bool finish) {
    animIsFinish=finish;
}


//	PROGRESS BAR

gui::ProgressBar::ProgressBar(
        float _x, float _y, float _width, float _height,
        int max_value, sf::Color innerColor, unsigned character_size,
        sf::VideoMode& vm, sf::Font* font)
{
    this->maxWidth = _width;
    this->maxValue = max_value;

    this->back.setSize(sf::Vector2f(_width, _height));
    this->back.setFillColor(sf::Color(50, 50, 50, 200));
    this->back.setPosition(_x, _y);

    this->inner.setSize(sf::Vector2f(_width, _height));
    this->inner.setFillColor(innerColor);
    this->inner.setPosition(this->back.getPosition());

    if (font) {
        this->text.setFont(*font);
        this->text.setCharacterSize(gui::calcCharSize(vm, character_size));
        this->text.setPosition(
                this->inner.getPosition().x + gui::p2pX(1.3f, vm),
                this->inner.getPosition().y + gui::p2pY(1.1f, vm));

    }



}

gui::ProgressBar::~ProgressBar()
{
}

void gui::ProgressBar::setMaxValue(int max){
    this->maxValue=max;
}
void gui::ProgressBar::setInnerColor(sf::Color color) {
    this->inner.setFillColor(color);
}

void gui::ProgressBar::update(const int current_value)
{
    float percent = static_cast<float>(current_value / static_cast<float>(this->maxValue));
    this->inner.setSize(
            sf::Vector2f(
                    static_cast<float>(std::floor(this->maxWidth * percent)),
                    this->inner.getSize().y
            )
    );

    this->barString = std::to_string(current_value) + " / " + std::to_string(this->maxValue);
    this->text.setString(this->barString);
}

void gui::ProgressBar::render(sf::RenderTarget & target)
{
    target.draw(this->back);
    target.draw(this->inner);
    target.draw(this->text);
}

