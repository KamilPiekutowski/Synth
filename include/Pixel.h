#ifndef PIXEL_H
#define PIXEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>


namespace sf{
    class Pixel: public Drawable
    {
        public:
            Pixel();
            virtual ~Pixel();

        protected:
        private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
///         // You can draw other high-level objects
///         target.draw(m_sprite, states);
///
///         // ... or use the low-level API
///         states.texture = &m_texture;
            //target.draw(m_vertices, states);
            // ... or draw with OpenGL directly
            //glBegin(GL_QUADS);
            //...
            //glEnd();
        }
    };
}

#endif // PIXEL_H
