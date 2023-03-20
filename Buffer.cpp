#include "includes/proj.hpp"

Buffer::Buffer() : VBO(0), VAO(0), EBO(0) {};

Buffer::Buffer(float vertices[], unsigned long szofv, unsigned int indices[], unsigned long szofin)
{
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, szofv, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, szofin, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
	// glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(1);  
};

Buffer::Buffer(const Buffer &a)
{
    this->EBO = a.getEBO();
    this->VBO = a.getVBO();
    this->VAO = a.getVAO();
};

Buffer & Buffer::operator = (const Buffer &a)
{
    if (this != &a)
    {
        this->EBO = a.getEBO();
        this->VBO = a.getVBO();
        this->VAO = a.getVAO();
    }
    return *this;
};

Buffer::~Buffer() {};

unsigned int Buffer::getVAO() const
{
    return this->VAO;
};

unsigned int Buffer::getVBO() const
{
    return this->VBO;
};

unsigned int Buffer::getEBO() const
{
    return this->EBO;
};