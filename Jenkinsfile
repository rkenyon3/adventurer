pipeline {
  agent{
    dockerfile {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }

  stages {
    stage('SCM') {
      steps{
        checkout(
          [
            $class: 'GitSCM',
            branches: scm.branches,
            userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }

    stage('Build') {
      steps {
        sh "ls"
        sh "cd adventurer"
        sh "mkdir build"
        sh "cd build"
        sh "cmake ../src"
        sh "cmake --build ."
      }
    }    
  }
}
