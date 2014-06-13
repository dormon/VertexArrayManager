#ifndef _VERTEXARRAYMANAGER_HPP_
#define _VERTEXARRAYMANAGER_HPP_

#include<GL/glew.h>
#include<BufferManager/CBufferManager.hpp>
#include<ShaderManager/CShaderProgram.hpp>

namespace NDormon{

	class CVertexArray{
		private:
			GLuint ID;///<ID of vertex array
		public:
			/**
			 * @brief Constructor of Vertex Array
			 */
			CVertexArray();
			/**
			 * @brief Destructor of Vertex Array
			 */
			~CVertexArray();
			/**
			 * @brief Adds Vertex Attribute
			 *
			 * @param Buffer Buffer
			 * @param Index Index of Vertex Attribute
			 * @param Size Number of components of Attribute
			 * @param Type Type of attribute
			 * @param Normalized Normalized
			 * @param Stride Stride in buffer in bytes
			 * @param OffSet Offset in buffer in bytes
			 */
			void AddAttrib(CBuffer*Buffer,GLuint Index,GLint Size,
					GLenum Type,GLboolean Normalized,GLsizei Stride,unsigned OffSet);
			/**
			 * @brief Adds Vertex Attribute
			 *
			 * @param Buffer Buffer
			 * @param Program Shader Program
			 * @param Name Name of attribute
			 * @param Stride Stride in buffer in bytes
			 * @param OffSet Offset in buffer in bytes
			 * @param Normalized Normalized
			 */
			void AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
					GLsizei Stride,unsigned OffSet,GLboolean Normalized=GL_FALSE);
			/**
			 * @brief Adds Vertex Attribute
			 *
			 * @param Buffer Buffer
			 * @param Program Shader Program
			 * @param Name Name of attribute
			 * @param Normalized Normalized
			 */
			void AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
					GLboolean Normalized=GL_FALSE);
			/**
			 * @brief Adds Vertex Attribute
			 *
			 * @param Buffer Buffer
			 * @param Program Shader Program
			 * @param Name Name of attribute
			 * @param NameOffSet if vertex attribute is array, this is offset
			 * @param Stride stride in buffer in bytes
			 * @param OffSet offset in buffer in bytes
			 * @param Normalized Normalized
			 */
			void AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
					unsigned NameOffSet,GLsizei Stride,unsigned OffSet,
					GLboolean Normalized=GL_FALSE);
			/**
			 * @brief Adds Vertex Attribute
			 *
			 * @param Buffer Buffer
			 * @param Program Shader Program
			 * @param Name Name of attribute
			 * @param NameOffSet if vertex attribute is array, this is offset
			 * @param Normalized Normalized
			 */
			void AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
					unsigned NameOffSet,GLboolean Normalized=GL_FALSE);
			/**
			 * @brief Bind this Vertex Array
			 */
			void Bind();
			/**
			 * @brief Unbind this Vertex Array
			 */
			void UnBind();
			/**
			 * @brief Checks if shader program is compatible with vertex array
			 *
			 * @param Program shader program
			 *
			 * @return returns true if shader program is compatible
			 */
			bool Compatible(CShaderProgram*Program);
	};
}

#endif//_VERTEXARRAYMANAGER_HPP_
