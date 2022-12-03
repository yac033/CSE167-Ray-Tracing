/**************************************************
RTScene.inl contains the definition of the scene graph
*****************************************************/
#include "RTScene.h"
#include "RTCube.h"

using namespace glm;
void RTScene::buildTriangleSoup(void){
    
    // Create a geometry palette
    RTgeometry["cube"] = new RTCube;
    // geometry["teapot"] = new Obj;
    // geometry["bunny"] = new Obj;
    RTgeometry["cube"] -> init();
    // geometry["teapot"] -> init("models/teapot.obj");
    // geometry["bunny"] -> init("models/bunny.obj");
    
    // Create a material palette
    material["wood"] = new Material;
    material["wood"] -> ambient = vec4(0.1f,0.1f,0.1f,1.0f);
    material["wood"] -> diffuse = vec4(0.3f,0.15f,0.1f,1.0f);
    material["wood"] -> specular = vec4(0.3f,0.15f,0.1f,1.0f);
    material["wood"] -> shininess = 100.0f;
    
    // material["ceramic"] = new Material;
    // material["ceramic"] -> ambient = vec4(0.02f, 0.07f, 0.2f, 1.0f);
    // material["ceramic"] -> diffuse = vec4(0.1f, 0.25f, 0.7f, 1.0f);
    // material["ceramic"] -> specular = vec4(0.9f, 0.9f, 0.9f, 1.0f);
    // material["ceramic"] -> shininess = 150.0f;
 
    // material["silver"] = new Material;
    // material["silver"] -> ambient = vec4(0.1f, 0.1f, 0.1f, 1.0f);
    // material["silver"] -> diffuse = vec4(0.2f, 0.2f, 0.2f, 1.0f);
    // material["silver"] -> specular = vec4(0.9f, 0.9f, 0.9f, 1.0f);
    // material["silver"] -> shininess = 50.0f;s
    // material["turquoise"] = new Material;
    // material["turquoise"] -> ambient = vec4(0.1f, 0.2f, 0.17f, 1.0f);
    // material["turquoise"] -> diffuse = vec4(0.2f, 0.375f, 0.35f, 1.0f);
    // material["turquoise"] -> specular = vec4(0.3f, 0.3f, 0.3f, 1.0f);
    // material["turquoise"] -> shininess = 100.0f;
    
    // material["bulb"] = new Material;
    // material["bulb"] -> ambient = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    // material["bulb"] -> diffuse = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    // material["bulb"] -> specular = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    // material["bulb"] -> emision = vec4(1.0f,0.2f,0.1f,1.0f);
    // material["bulb"] -> shininess = 200.0f;
    
    // Create a model palette
    model["box"] = new RTModel;
    model["box"] -> RTgeometry = RTgeometry["cube"];
    model["box"] -> material = material["wood"];
    

    // model["teapot1"] = new Model;
    // model["teapot1"] -> geometry = geometry["teapot"];
    // model["teapot1"] -> material = material["silver"];
    // model["teapot2"] = new Model;
    // model["teapot2"] -> geometry = geometry["teapot"];
    // model["teapot2"] -> material = material["ceramic"];
    // model["table piece"] = new Model;
    // model["table piece"] -> geometry = RTgeometry["cube"];
    // model["table piece"] -> material = material["wood"];
    // model["bunny"] = new Model;
    // model["bunny"] -> geometry = geometry["bunny"];
    // model["bunny"] -> material = material["turquoise"];
    // model["bulb"] = new Model;
    // model["bulb"] -> geometry = geometry["cube"];
    // model["bulb"] -> material = material["bulb"];
    
    // Create a light palette
    // light["sun"] = new Light;
    // light["sun"] -> position = vec4(3.0f,2.0f,1.0f,0.0f);
    // light["sun"] -> color = 1.0f*vec4(1.0f,1.0f,1.0f,1.0f);
    
    // light["bulb"] = new Light;
    // light["bulb"] -> position = vec4(0.0f,2.0f,0.0f,0.0f);
    // light["bulb"] -> color = 1.5f * vec4(1.0f,0.2f,0.1f,1.0f);
    
    // Build the scene graph
    node["box"] = new RTNode;
    node["box"]->models.push_back(model["box"]);
    node["box"]->modeltransforms.push_back(mat4(1.0f));
    // node["table"] = new RTNode;

    // node["table top"] = new RTNode;
    // node["table leg"] = new Node;
    // node["teapot1"] = new Node;
    // node["teapot2"] = new Node;
    // node["bunny"] = new Node;
    
    
    // node["table"] -> childnodes.push_back( node["table top"] );
    // node["table"] -> childtransforms.push_back( translate(vec3(0.0f,1.2f,0.0f)) );
    // node["table"] -> childnodes.push_back( node["table leg"] );
    // node["table"] -> childtransforms.push_back( translate(vec3(-0.9f,0.0f,-0.4f)) );
    // node["table"] -> childnodes.push_back( node["table leg"] );
    // node["table"] -> childtransforms.push_back( translate(vec3(-0.9f,0.0f,0.4f)) );
    // node["table"] -> childnodes.push_back( node["table leg"] );
    // node["table"] -> childtransforms.push_back( translate(vec3(0.9f,0.0f,0.4f)) );
    // node["table"] -> childnodes.push_back( node["table leg"] );
    // node["table"] -> childtransforms.push_back( translate(vec3(0.9f,0.0f,-0.4f)) );
    
    // node["table leg"] -> models.push_back( model["table piece"] );
    // node["table leg"] -> modeltransforms.push_back( translate(vec3(0.0f,0.5f,0.0f)) * scale(vec3(0.2f,1.0f,0.2f)) );
    
    // node["table top"] -> models.push_back( model["table piece"] );
    // node["table top"] -> modeltransforms.push_back( translate(vec3(0.0f,-0.1f,0.0f)) * scale(vec3(2.0f,0.2f,1.0f)) );
    // node["table top"] -> childnodes.push_back( node["teapot1"] );
    // node["table top"] -> childtransforms.push_back( translate(vec3(-0.5f,0.0f,0.0f)) );
    // node["table top"] -> childnodes.push_back( node["teapot2"] );
    // node["table top"] -> childtransforms.push_back( translate(vec3( 0.5f,0.0f,0.0f)) * rotate( -120.0f*float(M_PI)/180.0f, vec3(0.0f, 1.0f, 0.0f) ) );
    
    // node["teapot1"] -> models.push_back( model["teapot1"] );
    // node["teapot1"] -> modeltransforms.push_back( scale(vec3(0.5f)) );
    // node["teapot2"] -> models.push_back( model["teapot2"] );
    // node["teapot2"] -> modeltransforms.push_back( scale(vec3(1.0f,1.5f,1.0f)) * scale(vec3(0.5f)) );
    
    // node["bunny"] -> models.push_back( model["bunny"] );
    // node["bunny"] -> modeltransforms.push_back( scale(vec3(0.8f)) * translate(vec3(0.0f,1.0f,0.0f)) );
    
    node["world"] -> childnodes.push_back( node["box"] );
    node["world"] -> childtransforms.push_back( mat4(1.0f) );

    // node["world"] -> childnodes.push_back( node["table"] );
    // node["world"] -> childtransforms.push_back( mat4(1.0f) );
    // node["world"] -> childnodes.push_back( node["bunny"] );
    // node["world"] -> childtransforms.push_back( translate(vec3(-1.8f,0.0f,0.0f)) * rotate( 90.0f*float(M_PI)/180.0f, vec3(0.0f, 1.0f, 0.0f) ));
    // node["world"] -> models.push_back( model["bulb"] );
    // node["world"] -> modeltransforms.push_back( translate(vec3(0.0f,2.0f,0.0f))*scale(vec3(0.1f)) );
    
    // Put a camera
    camera = new Camera;
    camera -> target_default = vec3( 0.0f, 1.0f, 0.0f );
    camera -> eye_default = vec3( 0.0f, 1.0f, 5.0f );
    camera -> up_default = vec3( 0.0f, 1.0f, 0.0f );
    camera -> reset();
    
    // Initialize shader
    shader = new SurfaceShader;
    shader -> read_source( "shaders/projective.vert", "shaders/lighting.frag" );
    shader -> compile();
    glUseProgram(shader -> program);
    shader -> initUniforms();
    
    
    // Define stacks for depth-first search (DFS)
    std::stack < RTNode* > dfs_stack;
    std::stack < mat4 >  matrix_stack; // HW3: You will update this matrix_stack during the depth-first search while loop.
    
    // Initialize the current state variable for DFS
    RTNode* cur = node["world"]; // root of the tree
    mat4 cur_VM = camera -> view; // HW3: You will update this current modelview during the depth first search.  Initially, we are at the "world" node, whose modelview matrix is just camera's view matrix.
    
    // HW3: The following is the beginning of the depth-first search algorithm.
    // HW3: The depth-first search for the node traversal has already been implemented (cur, dfs_stack).
    // HW3: All you have to do is to also update the states of (cur_VM, matrix_stack) alongside the traversal.  You will only need to modify starting from this line.
    dfs_stack.push(cur);
    /**
     * TODO: (HW3 hint: you should do something here)
     */
    matrix_stack.push(cur_VM);
    // Compute total number of connectivities in the graph; this would be an upper bound for
    // the stack size in the depth first search over the directed acyclic graph
    int total_number_of_edges = 0; 
    for ( const auto &n : node ) total_number_of_edges += n.second->childnodes.size();
    
    // If you want to print some statistics of your scene graph
    // std::cout << "total numb of nodes = " << node.size() << std::endl;
    // std::cout << "total number of edges = " << total_number_of_edges << std::endl;
    
    while( ! dfs_stack.empty() ){
        // Detect whether the search runs into infinite loop by checking whether the stack is longer than the number of edges in the graph.
        if ( dfs_stack.size() > total_number_of_edges ){
            std::cerr << "Error: The scene graph has a closed loop." << std::endl;
            exit(-1);
        }
        
        // top-pop the stacks
        cur = dfs_stack.top();  dfs_stack.pop();
        /**
         * TODO: (HW3 hint: you should do something here)
         */
        cur_VM = matrix_stack.top(); matrix_stack.pop();
        // draw all the models at the current node
        // std::cout << cur-> << std::endl;

        for ( size_t i = 0; i < cur -> models.size(); i++ ){
            // Prepare to draw the geometry. Assign the modelview and the material.
            /**
             * TODO: (HW3 hint: you should do something here)
             */
            shader -> modelview = cur_VM * cur->modeltransforms[i]; // TODO: HW3: Without updating cur_VM, modelview would just be camera's view matrix.
            shader -> material  = ( cur -> models[i] ) -> material;
            
            // The draw command
            shader -> setUniforms();
            std::vector<Triangle> current_triangle = ( cur -> models[i] ) -> RTgeometry -> elements;
            for(Triangle i : current_triangle){
                Triangle temp_tri;
                temp_tri.P.push_back(i.P[0] * cur_VM)
                triangle_soup.push_back(i);
                // std::cout << i.P[0].x << std::endl;
            }
        }
        
        // Continue the DFS: put all the child nodes of the current node in the stack
        for ( size_t i = 0; i < cur -> childnodes.size(); i++ ){
            dfs_stack.push( cur -> childnodes[i] );
            /**
             * TODO: (HW3 hint: you should do something here)
             */
            matrix_stack.push( cur_VM * cur->childtransforms[i] );
        }
    } // End of DFS while loop.
    // std::cout << triangle_soup.size() << std::endl;
}
