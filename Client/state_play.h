#pragma once

#include "state_interface.h"
#include "darwin_client.h"
#include "frame/common/application.h"
#include "Common/world_simulator.h"

namespace darwin::state {

    class StatePlay : public StateInterface {
    public:
        StatePlay(
            frame::common::Application& app, 
            std::unique_ptr<darwin::DarwinClient> darwin_client);
        ~StatePlay() override = default;
        void Enter() override;
        void Update(StateContext& state_context) override;
        void Exit() override;

    protected:
        frame::ProgramInterface& GetProgram();
        void UpdateUniformSpheres(
            frame::ProgramInterface& program,
            darwin::UniformEnum& uniforms);
        void UpdateUniformCamera(
            frame::ProgramInterface& program,
            const proto::Character& character);

    private:
        frame::common::Application& app_;
        std::unique_ptr<darwin::DarwinClient> darwin_client_;
        std::string user_name_;
        frame::Logger& logger_ = frame::Logger::GetInstance();
        WorldSimulator world_simulator_;
        // Camera parameters.
        float camera_yaw_ = 0.0f;
        float camera_pitch_ = -20.0f;
        float camera_distance_ = 5.0f;
        glm::vec3 forward_ = glm::vec3(0.0f);
        glm::vec3 center_ = glm::vec3(0.0f);
    };

} // namespace darwin::state.
