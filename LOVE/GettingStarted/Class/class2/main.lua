function love.load()
    require "shape" -- shape required in both
                    -- rectangle and circle
                    -- only need to call once
    require "rectangle"
    require "circle"
    x = 100
    y = 100
    r1 = Rectangle(x, y, 200, 50)
    r2 = Circle(x, y + 200, 50)
end

function love.draw()
    r1:draw()
    r2:draw()
end

function love.update(dt)
    r1:update(dt)
    r2:update(dt)
end