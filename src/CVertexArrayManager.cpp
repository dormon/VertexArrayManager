#include"CVertexArrayManager.hpp"

namespace NDormon{
	
	CVertexArray::CVertexArray(){
		glGenVertexArrays(1,&this->ID);
	}

	CVertexArray::~CVertexArray(){
    glDeleteVertexArrays(1,&this->ID);
	}

	void CVertexArray::AddAttrib(CBuffer*Buffer,GLuint Index,GLint Size,
			GLenum Type,GLboolean Normalized,GLsizei Stride,unsigned OffSet){
		this->Bind();
		Buffer->Bind(GL_ARRAY_BUFFER);
		glVertexAttribPointer(Index,Size,Type,Normalized,Stride,(GLvoid*)(sizeof(char)*OffSet));
		this->UnBind();
		Buffer->UnBind(GL_ARRAY_BUFFER);
	}

	void CVertexArray::AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
			GLsizei Stride,unsigned OffSet,GLboolean Normalized){
		this->Bind();
		Buffer->Bind(GL_ARRAY_BUFFER);
		GLenum Type=Program->GetAttributeType(Name);
		glVertexAttribPointer(
				Program->GetAttribute(Name),
				NDormon::ComplexTypeToSize(Type),
				NDormon::ComplexTypeToSimpleType(Type),
				Normalized,
				Stride,
				(GLvoid*)(sizeof(char)*OffSet));
		this->UnBind();
		Buffer->UnBind(GL_ARRAY_BUFFER);
	}
	
	void CVertexArray::AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
			GLboolean Normalized){
		this->Bind();
		Buffer->Bind(GL_ARRAY_BUFFER);
		GLenum Type=Program->GetAttributeType(Name);
		glVertexAttribPointer(
				Program->GetAttribute(Name),
				NDormon::ComplexTypeToSize(Type),
				NDormon::ComplexTypeToSimpleType(Type),
				Normalized,
				0,
				NULL);
		this->UnBind();
		Buffer->UnBind(GL_ARRAY_BUFFER);
	}
	void CVertexArray::AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
			unsigned NameOffSet,GLsizei Stride,unsigned OffSet,
			GLboolean Normalized){
		this->Bind();
		Buffer->Bind(GL_ARRAY_BUFFER);
		GLenum Type=Program->GetAttributeType(Name);
		glVertexAttribPointer(
				Program->GetAttribute(Name)+NameOffSet,
				NDormon::ComplexTypeToSize(Type),
				NDormon::ComplexTypeToSimpleType(Type),
				Normalized,
				Stride,
				(GLvoid*)(sizeof(char)*OffSet));
		this->UnBind();
		Buffer->UnBind(GL_ARRAY_BUFFER);
	}
	void CVertexArray::AddAttrib(CBuffer*Buffer,CShaderProgram*Program,std::string Name,
			unsigned NameOffSet,GLboolean Normalized){
		this->Bind();
		Buffer->Bind(GL_ARRAY_BUFFER);
		GLenum Type=Program->GetAttributeType(Name);
		glVertexAttribPointer(
				Program->GetAttribute(Name)+NameOffSet,
				NDormon::ComplexTypeToSize(Type),
				NDormon::ComplexTypeToSimpleType(Type),
				Normalized,
				0,
				NULL);
		this->UnBind();
		Buffer->UnBind(GL_ARRAY_BUFFER);
	}
	void CVertexArray::Bind(){
		glBindVertexArray(this->ID);
	}
	void CVertexArray::UnBind(){
		glBindVertexArray(0);
	}
	/*bool CVertexArray::Compatible(CShaderProgram*Program);
	*/
}
