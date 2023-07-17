pipeline 
{
  agent 
  {
    dockerfile 
    {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }
  stages 
  {
    stage('SCM') 
    {
      steps 
      {
        checkout(
          [
					  $class: 'GitSCM',
						branches: scm.branches,
    				userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }
    stage('Build')
    {
      steps
      {
        sh 'mkdir build && cd build && cmake .. && make'
      }
    }
    stage('Test')
    {
      steps
      {
        sh 'echo Test placeholder'
      }
    }
    stage('Deploy')
    {
      steps
      {
        sh 'echo Deploy placeholder'
      }
    }    
  }
}
