#include "Diver.h"
using namespace std;

//constructor
Diver::Diver(){
  m_myName = "Gokul";
  m_numMaterials = 0;
  Material m_myMaterials[PROJ2_SIZE] = {};
}

string Diver::GetName(){
  return m_myName; 
}

void Diver::SetName(string name){
  m_myName = name; 
}

string Diver::ShowMaterial(int index){
  return m_myMaterials[index].m_name; 
}
  // Name: DisplayMaterials()
  // Desc - Displays a numbered list of all materials known by the Diver
  // Preconditions - Diver exists
  // Postconditions - Displays all materials
void Diver::DisplayMaterials(){
  for (int i = 0; i < m_numMaterials ; i++ ){
      cout << i + 1 << ". " << m_myMaterials[i].m_name << m_myMaterials[i].m_quantity << endl;
    }  
  }

  // Name: CheckMaterial(Material)
  // Desc - Checks to see if the Diver has a material
  // Preconditions - Diver already has materials
  // Postconditions - Returns index of material if Diver has it else -1
int Diver::CheckMaterial(Material aMaterial){
  for (int i = 0; i < m_numMaterials; i++ ){
    if (aMaterial.m_name == m_myMaterials[i].m_name && aMaterial.m_quantity > 0)
      return i;
    else 
      return -1;
  }
}

  // Name: AddMaterial(Material)
  // Desc - Inserts a material into the Diver's list of materials
  // Preconditions - Diver exists
  // Postconditions - Add a material to the Diver's m_myMaterials with a quantity of 0
void Diver::AddMaterial(Material aMaterial) {
  aMaterial.m_quantity = 0;
  m_myMaterials[m_numMaterials++] = aMaterial;
  //m_numMaterials++;
}

  // Name: IncrementQuantity(Material)
  // Desc - Adds quantity to list of materials the diver knows
  // Preconditions - Diver exists
  // Postconditions - Increases quantity of material for diver
  void Diver::IncrementQuantity(Material aMaterial){
    for (int i = 0; i < m_numMaterials; i++ )
      if (aMaterial.m_name == m_myMaterials[i].m_name)
        aMaterial.m_quantity++;
  }

  // Name: DecrementQuantity(Material)
  // Desc - Reduces quantity from diver's inventory with true, if no quantity false
  // Preconditions - Diver exists
  // Postconditions - Reduces quantity of material for diver
  bool Diver::DecrementQuantity(Material aMaterial){
   for (int i = 0; i < m_numMaterials; i++ )
      if (aMaterial.m_name == m_myMaterials[i].m_name && aMaterial.m_quantity > 0){
        aMaterial.m_quantity--;
        return true;
      }
      else 
        return false; 
  
  }

  // Name: CheckQuantity(Material, Material)
  // Desc - Checks to see if quantity of two merge materials are available
  // Preconditions - Diver exists with materials
  // Postconditions - Returns true if both are available (including two of same material)
  bool Diver::CheckQuantity(Material aMaterial, Material bMaterial) {
    if ((aMaterial.m_quantity > 0) && (bMaterial.m_quantity > 0))
      return true;
    else
      return false;
  }

    // Name: GetMaterial(int)
  // Desc - Checks to see if the diver has a material
  // Preconditions - Diver already has materials
  // Postconditions - Returns material of index 
  Material Diver::GetMaterial(int index) {
        return m_myMaterials[index]; 
  }

    // Name: CalcDepth(int)
  // Desc - Checks the total depth of all unique materials known/built
  // Preconditions - Diver already has materials
  // Postconditions - Returns depth sum of all unique materials owned/built
  int Diver::CalcDepth(){
    int depth = 0;
    for (int i = 0; i < m_numMaterials; i++){
      if (m_myMaterials[i].m_quantity > 0){
          depth = depth + m_myMaterials[i].m_depth; 
      }
    }
  }