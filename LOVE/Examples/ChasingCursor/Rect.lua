-- Features
    -- print a rectangle
    -- the rectangle chases the cursor
--[[ TODO
    -- the rectangle doesn't go in a diagonal when
       -- the shape of the rectangle that formed by the
       -- two points is not square
       -- so program such that the rectangle goes along the 
       -- Euclidean distance   
]]

Rect = Class{}

function Rect:init(x, y, width, height)
    -- coordinates
    self.x = x
    self.y = y

    -- size
    self.width = width
    self.height = height

    -- velocity 
    self.dx = 10 
    self.dy = 10 

end

function Rect:collides()
end

function Rect:update(dt, cursorX, cursorY)
    if self.x <= cursorX and self.y <= cursorY then
        self.x = self.x + (cursorX - self.dx)/2 * dt
        self.y = self.y + (cursorY - self.dy)/2 * dt
    end

    if self.x <= cursorX and self.y >= cursorY then
        self.x = self.x + (cursorX - self.dx)/2 * dt
        self.y = self.y - (cursorY - self.dy)/2 * dt
    end

    if self.x >= cursorX and self.y <= cursorY then
        self.x = self.x - (cursorX - self.dx)/2 * dt
        self.y = self.y + (cursorY - self.dy)/2 * dt
    end

    if self.x >= cursorX and self.y >= cursorY then
        self.x = self.x - (cursorX - self.dx)/2 * dt
        self.y = self.y - (cursorY - self.dy)/2 * dt
    end

end

--function Rect:reset()
--end

function Rect:render()
    love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end