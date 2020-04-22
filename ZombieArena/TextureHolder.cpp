#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
	// Create instance of TextureHolder
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// Get a reference to m_Textures map<string, Texture> using m_S_Instance
	auto& m = m_s_Instance->m_Textures;

	// Create an iterator and search
	auto keyValuePair = m.find(filename); // auto = map<string, Texture>::iterator

	// Match found, return texture
	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	} else {
		// Create a new key value pair using the filename
		auto& texture = m[filename];
		
		// Load texture from file
		texture.loadFromFile(filename);

		// Return new texture
		return texture;
	}
}