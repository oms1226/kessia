import gym
env = gym.make("FrozenLake-v0")
env.reset()

for _ in range(1000):
    env.render()
    action = env.action_space.sample()
    env.step(action)