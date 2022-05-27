#include "sphere.h"

namespace Shapes
{
    Sphere::Sphere(glm::vec3 pos, float radius, uint32_t sectors, uint32_t stacks)
        : _position{pos}, _radius{radius}
    {

        sectors = sectors > 3 ? sectors : 3;
        stacks = stacks > 2 ? stacks : 2;
        _vertices.emplace_back(pos.x, pos.y + radius, pos.z, 0.5f, 0);
        
        float dtx = 1.0f / sectors;
        float dty = 1.0f / stacks;
        float dv_angle = glm::pi<float>() / stacks;
        float dh_angle = glm::pi<float>() * 2 / sectors;
        float v_angle = dv_angle;
        glm::vec4 tmp{0.0f, radius, 0.0f, 1.0f};
        for (uint32_t lat = 1; lat < stacks; ++lat)
        {
            auto m4_ver_rot = glm::rotate(glm::mat4(1.0f), v_angle, glm::vec3(1.0f, 0.0f, 0.0f));
            auto ver = m4_ver_rot * tmp;
            float h_angle = 0;
            for (uint32_t lon = 1; lon <= sectors + 1; ++lon)//sectors + 1 -> for extra point to texture coord
            {
                auto m4_hor_rot = glm::rotate(glm::mat4(1.0f), h_angle, glm::vec3(0.0f, 1.0f, 0.0f));
                auto v4 = m4_hor_rot * ver;
                glm::vec3 res = glm::vec3(v4.x, v4.y, v4.z) + pos;
                _vertices.emplace_back(res, dtx*(lon-1), dty*lat);
                setIndices(_indices, stacks, lat, sectors, lon);
                h_angle += dh_angle;
            }
            v_angle += dv_angle;
        }
        _vertices.emplace_back(pos.x, pos.y - radius,pos.z, 0.5f, 1.0f);
        setLastStackIndices(_indices, stacks, sectors, _vertices.size() - 1);
    }

    void Sphere::setIndices(std::vector<uint32_t>& ind, uint32_t stacks, uint32_t lat, uint32_t sectors, uint32_t lon){
        if(lat == 0 || lon == 1)
            return;
        if(lat == 1){
            ind.emplace_back(0);
            ind.emplace_back(lon);
            ind.emplace_back(lon-1);
        }
        else{
            ind.emplace_back((sectors+1)*(lat-2) + lon - 1);
            ind.emplace_back((sectors+1)*(lat-1) + lon);
            ind.emplace_back((sectors+1)*(lat-1) + lon - 1);

            ind.emplace_back((sectors+1)*(lat-2) + lon - 1);
            ind.emplace_back((sectors+1)*(lat-2) + lon);
            ind.emplace_back((sectors+1)*(lat-1) + lon);
        }
    }

    void Sphere::setLastStackIndices(std::vector<uint32_t>& inds, uint32_t stacks, uint32_t sectors, uint32_t last){
        uint32_t first = last - sectors - 1;
        for(uint32_t ind = first + 1; ind < last; ++ind){
            inds.emplace_back(ind - 1);
            inds.emplace_back(ind);
            inds.emplace_back(last);
        }
    }

} // namespace Shapes
