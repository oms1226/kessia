#include "q_predictor.h"

float predictor_output[Q_PREDICTOR_MODELS_COUNT] =
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

float predictor_hard_locations[Q_PREDICTOR_MODELS_COUNT][Q_PREDICTOR_MODEL_SIZE] =
    {
      {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
      {0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3, 0.3},
      {0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6},
      {0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8},

      {0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.012, 0.050, 0.113, 0.200, 0.312, 0.450, 0.613, 0.800, 1.000},

      {0.000, 0.025, 0.100, 0.225, 0.400, 0.625, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},

      {0.000, 0.050, 0.200, 0.450, 0.800, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},


      {0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000, 1.000},
      {0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.100, 0.400, 0.900, 1.000}
    };



CQPredictor::CQPredictor()
{
  init();
}

CQPredictor::~CQPredictor()
{

}


void CQPredictor::init()
{
  u32 i;

  for (i = 0; i < Q_PREDICTOR_MODEL_SIZE; i++)
    input[i] = 0.0;
}



float CQPredictor::process(float input_sample)
{
  float eta = 0.98;
  float kappa = 1.0/Q_PREDICTOR_MODEL_SIZE;

  u32 i, j;

  /*add new sample into fifo front*/
  for (i = (Q_PREDICTOR_MODEL_SIZE-1); i != 0; i--)
    input[i] = input[i-1];
  input[0] = m_abs(input_sample);

  dist_min_idx = 0;
  float dist_min = 1000000.0;
  for (j = 0; j < Q_PREDICTOR_MODELS_COUNT; j++)
  {
    float dist = 0.0;
    for (i = 0; i < Q_PREDICTOR_MODEL_SIZE; i++)
      //dist+= (1.0/(kappa*i + 1.0)) * m_abs(input[i] - predictor_hard_locations[j][i]);
      dist+= m_abs(input[i] - predictor_hard_locations[j][i]);

    if (dist < dist_min)
    {
      dist_min = dist;
      dist_min_idx = j;
    }
  } 

  float sum = 0.0;
  for (i = 0; i < Q_PREDICTOR_MODEL_SIZE; i++)
    sum+= input[i];
  sum = sum / Q_PREDICTOR_MODEL_SIZE;

  predictor_output[dist_min_idx] = eta*predictor_output[dist_min_idx] + (1.0 - eta)*sum;

  return -m_sgn(input_sample)*predictor_output[dist_min_idx];
}

void CQPredictor::print()
{
  printf_("> %u : ", dist_min_idx);
  u32 i;
  for (i = 0; i < Q_PREDICTOR_MODELS_COUNT; i++)
    printf_("%i ", (i32)(predictor_output[i]*1000) );
  printf_("\n");
}
