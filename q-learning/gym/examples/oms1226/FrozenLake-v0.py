#-*- coding: utf-8 -*-
"""
http://www.modulabs.co.kr/index.php?mid=RL4RWS&page=2&document_srl=18798
"""
import gym
env = gym.make("FrozenLake-v0")


if False:
    env.reset()
    for _ in range(1000):
        env.render()
        action = env.action_space.sample()
        env.step(action)

if False:
    env.reset()
    done = None
    while not done:                            # 게임 한판
        env.render()
        action = env.action_space.sample()
        state, reward, done, _ = env.step(action)


num_episodes = 1000
for i in range(num_episodes) : # 학습을 num_episodes 만큼 시키면서 업데이트
    env.reset()
    done = None
    while not done:                            # 게임 한판
        #####env.render()                      # 속도를 위해 주석 처리함
        action = env.action_space.sample()
        state, reward, done, _ = env.step(action)
    env.render()                               # 에피소드가 끝날 때 마다 상태 확인