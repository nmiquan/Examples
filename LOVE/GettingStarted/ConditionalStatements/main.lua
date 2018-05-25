-- Source: sheepolution

-- Game Loop
-- love.load -> love.update -> love.draw -> love.update 
-- -> love.draw

function love.load()
    x = 100
    y = 100
end

function love.draw()
    --love.graphics.rectangle("fill", 0, 0, 1280/2, 720/2)
    --love.graphics.rectangle("line", x, 50, 200, 150)
    love.graphics.rectangle("fill", x, y, 100, 100)
end

function love.update(dt)
    -- dt = delta time
    -- computer A: 100fps, delta time = 1/100 (on average)
    -- computer B: 200fps, delta time = 1/200 (on average)
    -- scaling with delta time
    -- x changes on
    -- computer A: 100 * 5 * 1/100 = 5
    -- computer B: 200 * 5 * 1/200 = 5
    -- not scaling with delta time
    -- x changes on
    -- computer A: 100 * 5 = 500
    -- computer B: 200 * 5 = 1000
    -- WHAT IS THE UNIT OF x?

    --if x < 700 then
    --   x = x + 50 * dt
    --end

    if love.keyboard.isDown('w') and love.keyboard.isDown('a') then
        y = y - 50 * dt
        x = x - 50 * dt
    elseif love.keyboard.isDown('w') and love.keyboard.isDown('d') then
        y = y - 50 * dt
        x = x + 50 * dt
    elseif love.keyboard.isDown('s') and love.keyboard.isDown('a') then
        y = y + 50 * dt
        x = x - 50 * dt
    elseif love.keyboard.isDown('s') and love.keyboard.isDown('d') then
        y = y + 50 * dt
        x = x + 50 * dt
    elseif love.keyboard.isDown('w') then
        y = y - 50 * dt
    elseif love.keyboard.isDown('s') then
        y = y + 50 * dt
    elseif love.keyboard.isDown('a') then
        x = x - 50 * dt
    elseif love.keyboard.isDown('d') then
        x = x + 50 * dt

    end
end