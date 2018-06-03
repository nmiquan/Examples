-- References 
    -- https://en.wikipedia.org/wiki/Sweep_and_prune
    -- https://gamedevelopment.tutsplus.com/tutorials/collision-detection-using-the-separating-axis-theorem--gamedev-169

-- Features
    -- click on a rectangle results in changing color
    -- hold left mouse
        -- the rectangle chases after the cursor
        -- only if the cursor is inside the rectangle

--[[ TODO
    -- hold left mouse
        -- the rectangle chases after the cursor
        -- even if the cursor is still held 
        -- and has gone outside of the rect
    -- collision to other rectangles results in
        -- impacted rectangle moves, decelerate over time
    -- changing color
        -- only selected rectangle
    -- have a mix of rectangle, circle, line
       -- AABB intersection 
       -- Sphere intersection
       -- Line intersection
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
    self.dx = 50 -- size of the rectangle limits 
    self.dy = 50 -- how much the rectangle moves

    -- if leftMouse is held
    -- the distance from cursor to object's origin is fixed
    self.midX = self.width/2 
    self.midY = self.height/2 

end

function Rect:update(dt, anotherRect)
    if not heldWithin(self) then
        if not collides(self, anotherRect) then
            message = 'collides'
            -- makes the rectangle bounces out
            self.x = self.x + someDiffX
            self.y = self.y + someDiffY
        else
            self.x = self.x + (cursorX - self.x - self.midX) * self.dx * dt
            self.y = self.y + (cursorY - self.y - self.midY) * self.dy * dt
        end
    end
end

function collides(rect1, rect2)
    if rect1.x + rect1.width > rect2.x
    and rect1.x < rect2.x + rect2.width 
    and rect1.y < rect2.y + rect2.height
    and rect1.y + rect1.height > rect2.y then
        someDiffX = (rect1.x - rect2.x)
        someDiffY = (rect1.y - rect2.y)
        return true    
    else
        return false 
    end
end

function Rect:render()
    if heldWithin(self) then
        love.graphics.setColor(255, 0, 0, 1)
        love.graphics.rectangle(
            'fill', 
            self.x, 
            self.y, 
            self.width, 
            self.height 
        )
    else
        love.graphics.setColor(1, 1, 1, 1)
        love.graphics.rectangle(
            'fill', 
            self.x, 
            self.y, 
            self.width, 
            self.height 
        )
    end
end

function heldWithin(self)
    -- WHY DOESN'T Rect:heldWithin() WORK?
    if cursorX >= self.x
    and cursorY >= self.y 
    and cursorX <= self.x + self.width
    and cursorY <= self.y + self.height
    and love.mouse.isDown(1) then
        return true
    else
        return false
    end
end