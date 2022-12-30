#ifndef DSAP_CUSTOM_CONTROLLER_H
#define DSAP_CUSTOM_CONTROLLER_H

#include "ISnakeController.h"
#include "DirectionType.h"

class CustomController : public ISnakeController
{
public:
    DirectionType NextDirection(const Game &game, size_t id)
    {
        return TestA_method(game);
    }

private:
    ////for testA
    const float safe_dis = 250;
    const float attainable_angle = 90;
    DirectionType cur_dir = DirectionType::kForward;
    bool det_by_emergency = false;
    float det_dir;
    //// for testA
    DirectionType TestA_method(const Game &game)
    {
        if (game.Time() < 20)
        {
            return DirectionType::kForward;
        }
        const auto &snake = game.Snakes().at(1);
        float min_dis = Position{static_cast<float>(game.FieldHeight()), static_cast<float>(game.FieldWidth())}.Length();
        Position tarFood = snake.Head();
        float snake_direction = static_cast<int>(snake.Direction()) % 360 + (snake.Direction() < 0 ? 360 : 0);
        if (det_by_emergency)
        {
            if (game.Time() - 15 < delay)
            {
                return cur_dir;
            }
            if (abs(snake_direction - det_dir) < 10)
            {
                det_by_emergency = false;
            }
            // std::cout << "emergency" << "\n";
            return cur_dir;
        }
        for (const auto &food : game.Foods())
        {
            Position x = snake.Head() - food;
            float dis = x.Length();
            if (dis < min_dis)
            {
                if (attainable(food, snake.Head(), snake_direction))
                {
                    min_dis = dis;
                    tarFood = food;
                }
            }
        }
        float remain_angle = get_remain_angle(tarFood, snake.Head(), snake_direction);
        // std::cout << remain_angle << ", " << min_dis << "\n";
        if (abs(remain_angle) > 60 && min_dis < 150)
        {
            cur_dir = DirectionType::kForward;
        }
        else if (remain_angle < 0 && remain_angle > -attainable_angle)
        {
            cur_dir = DirectionType::kLeft;
        }
        else if (remain_angle > 0 && remain_angle < attainable_angle)
        {
            cur_dir = DirectionType::kRight;
        }
        else
        {
            cur_dir = DirectionType::kForward;
        }
        if (game.Snakes().size() > 1)
        {
            cur_dir = emergency2_procedures(game, cur_dir);
        }
        cur_dir = emergency_procedures(game, cur_dir);
        return cur_dir;
    }
    bool attainable(Position tarFood, Position snake_head, float snake_direction) //// for testA
    {
        Position dir = tarFood - snake_head;
        float dir_angle = dir.InnerProduct({1, 0}) / dir.Length();
        dir_angle = dir.y > 0 ? acos(dir_angle) : -acos(dir_angle) + 2 * M_PI;
        dir_angle = dir_angle * 180 / M_PI;
        float remain_angle = dir_angle - snake_direction;
        if (remain_angle > 180 && remain_angle < 360)
            remain_angle -= 360;
        if (remain_angle < -180 && remain_angle > -360)
            remain_angle += 360;
        if (remain_angle > -attainable_angle && remain_angle < attainable_angle)
        {
            return true;
        }
        return false;
    }
    float get_remain_angle(Position tarFood, Position snake_head, float snake_direction) //// for testA
    {
        Position dir = tarFood - snake_head;
        float dir_angle = dir.InnerProduct({1, 0}) / dir.Length();
        dir_angle = dir.y > 0 ? acos(dir_angle) : -acos(dir_angle) + 2 * M_PI;
        dir_angle = dir_angle * 180 / M_PI;
        float remain_angle = dir_angle - snake_direction;
        if (remain_angle > 180 && remain_angle < 360)
            remain_angle -= 360;
        if (remain_angle < -180 && remain_angle > -360)
            remain_angle += 360;
        return remain_angle;
    }
    DirectionType emergency_procedures(const Game &game, DirectionType result) //// for testA
    {
        const auto &snake = game.Snakes().at(1);
        float snake_direction = static_cast<int>(snake.Direction()) % 360 + (snake.Direction() < 0 ? 360 : 0);
        bool up = snake.Head().y < safe_dis;
        bool down = static_cast<float>(game.FieldHeight()) - snake.Head().y < safe_dis;
        bool right = static_cast<float>(game.FieldWidth()) - snake.Head().x < safe_dis;
        bool left = snake.Head().x < safe_dis;
        if (up)
        {
            if (right)
            {
                det_dir = 135;
                det_by_emergency = true;
                float remain_angle = static_cast<int>(135 - snake_direction + 360) % 360;
                if (remain_angle > 180)
                {
                    return DirectionType::kLeft;
                }
                else
                {
                    return DirectionType::kRight;
                }
            }
            if (left)
            {
                det_dir = 45;
                det_by_emergency = true;
                float remain_angle = static_cast<int>(45 - snake_direction + 360) % 360;
                if (remain_angle > 180)
                {
                    return DirectionType::kLeft;
                }
                else
                {
                    return DirectionType::kRight;
                }
            }
            result = snake.Forward().x > 0 ? DirectionType::kRight : DirectionType::kLeft;
        }
        if (down)
        {
            if (right)
            {
                det_dir = 225;
                det_by_emergency = true;
                float remain_angle = static_cast<int>(225 - snake_direction + 360) % 360;
                if (remain_angle > 180)
                {
                    return DirectionType::kLeft;
                }
                else
                {
                    return DirectionType::kRight;
                }
            }
            if (left)
            {
                det_dir = 315;
                det_by_emergency = true;
                float remain_angle = static_cast<int>(315 - snake_direction + 360) % 360;
                if (remain_angle > 180)
                {
                    return DirectionType::kLeft;
                }
                else
                {
                    return DirectionType::kRight;
                }
            }
            return snake.Forward().x > 0 ? DirectionType::kLeft : DirectionType::kRight;
        }
        if (right)
        {
            return snake.Forward().y > 0 ? DirectionType::kRight : DirectionType::kLeft;
        }
        if (left)
        {
            return snake.Forward().y > 0 ? DirectionType::kLeft : DirectionType::kRight;
        }
        return result;
    }
    DirectionType emergency2_procedures(const Game &game, DirectionType result) //// for testA
    {
        const auto &snake = game.Snakes().at(1);
        float snake_direction = static_cast<int>(snake.Direction()) % 360 + (snake.Direction() < 0 ? 360 : 0);
        Position enemy;
        float dis = 9999;
        for (int i = 2; i < game.Snakes().size(); i++)
        {
            if (!game.Snakes().count(i))
                continue;
            if ((game.Snakes().at(i).Head() - snake.Head()).Length() < dis)
            {
                enemy = game.Snakes().at(i).Head();
                dis = (game.Snakes().at(i).Head() - snake.Head()).Length();
            }
            for (auto v : game.Snakes().at(i).Body())
            {
                if ((v - snake.Head()).Length() < dis)
                {
                    enemy = v;
                    dis = (v - snake.Head()).Length();
                }
            }
        }
        if (dis < 260)
        {
            bool up = snake.Head().y > enemy.y;
            bool down = snake.Head().y <= enemy.y;
            bool right = snake.Head().x < enemy.x;
            bool left = snake.Head().x >= enemy.x;
            delay = game.Time();
            if (up)
            {
                if (right)
                {
                    det_dir = 225;
                    det_by_emergency = true;
                    if (0 <= snake_direction && snake_direction < 180)
                    {
                        if (0 <= snake_direction && snake_direction < 90)
                        {
                            return DirectionType::kRight;
                        }
                        else
                        {
                            return DirectionType::kLeft;
                        }
                    }
                    else
                    {
                        return DirectionType::kRight;
                    }
                }
                if (left)
                {
                    det_dir = 315;
                    det_by_emergency = true;
                    if (0 <= snake_direction && snake_direction < 180)
                    {
                        if (90 <= snake_direction && snake_direction < 180)
                        {
                            return DirectionType::kLeft;
                        }
                        else
                        {
                            return DirectionType::kRight;
                        }
                    }
                    else
                    {
                        return DirectionType::kLeft;
                    }
                }
                result = snake.Forward().x > 0 ? DirectionType::kRight : DirectionType::kLeft;
            }
            if (down)
            {
                if (right)
                {
                    det_dir = 135;
                    det_by_emergency = true;
                    if (180 <= snake_direction && snake_direction < 360)
                    {
                        if (270 <= snake_direction && snake_direction < 360)
                        {
                            return DirectionType::kLeft;
                        }
                        else
                        {
                            return DirectionType::kRight;
                        }
                    }
                    else
                    {
                        return DirectionType::kLeft;
                    }
                }
                if (left)
                {
                    det_dir = 45;
                    det_by_emergency = true;
                    if (180 <= snake_direction && snake_direction < 360)
                    {
                        if (180 <= snake_direction && snake_direction < 270)
                        {
                            return DirectionType::kRight;
                        }
                        else
                        {
                            return DirectionType::kLeft;
                        }
                    }
                    else
                    {
                        return DirectionType::kRight;
                    }
                }
                return snake.Forward().x > 0 ? DirectionType::kLeft : DirectionType::kRight;
            }
        }
        return result;
    }
    size_t delay;
};

#endif // DSAP_CUSTOM_CONTROLLER_H
